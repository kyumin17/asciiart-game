#include <iostream>
#include "make_element.hpp"

#define COLOR_DEPTH 8

using namespace std;

bool readImage(const char* fn, ImageInfo* image_info) {
	/*
	이미지의 정보를 받아옴
	*/

	/* 초기화 및 에러처리 */
	FILE *fp = fopen(fn, "rb");
	png_structp png_ptr;
	png_infop info_ptr;
	if (!fp) {
		cout << "ERROR: could not read image " << fn << endl;
		return false;
	}

	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) {
		cout << "ERROR: could not initialize png struct" << endl;
		return false;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr) {
		cout << "ERROR: could not init png information" << endl;
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		fclose(fp);
		return false;
	}

	if (setjmp(png_jmpbuf(png_ptr))) {
		cout << "ERROR: could not init png" << endl;
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		fclose(fp);
		return false;
	}

	png_init_io(png_ptr, fp);
	png_read_info(png_ptr, info_ptr);

	/* 이미지 정보 받아옴 */
	int width = png_get_image_width(png_ptr, info_ptr);
	int height = png_get_image_height(png_ptr, info_ptr);
	int color_type = png_get_color_type(png_ptr, info_ptr);

	if (color_type == PNG_COLOR_TYPE_RGB) {
		png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER); //rgb to rgba
	} else if (color_type != PNG_COLOR_TYPE_RGB_ALPHA) {
		cout << "ERROR: invalid color type" << endl;
	}

	png_read_update_info(png_ptr, info_ptr);

	png_bytep* row_pointers = (png_bytep *)malloc(sizeof(png_bytep) * height);
	for (int row  = 0; row < height; row++) {
		row_pointers[row] = (png_bytep)malloc(png_get_rowbytes(png_ptr, info_ptr));
	}

	png_read_image(png_ptr, row_pointers);

	/* image_info에 정보 입력 */
	image_info -> image = new Pixel*[height];
	for (int row = 0; row < height; row++) {
		image_info -> image[row] = new Pixel[width];
	}

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			image_info -> image[row][col].r = (int)row_pointers[row][col * 4];
			image_info -> image[row][col].g = (int)row_pointers[row][col * 4 + 1];
			image_info -> image[row][col].b = (int)row_pointers[row][col * 4 + 2];
			image_info -> image[row][col].a = (int)row_pointers[row][col * 4 + 3];
		}
	}

	image_info -> width = width;
	image_info -> height = height;

	/* 메모리 해제 */
	for (int row = 0; row < height; row++) {
		delete[] row_pointers[row];
	}
	delete[] row_pointers;

	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	fclose(fp);

	return true;
}

void makeElement(char id[MAXLEN], const char* fn, int width, int x, int y, char shape) {
	/* 이미지 읽어들임 */
	ImageInfo* image_info = new ImageInfo;
	readImage(fn, image_info);

	/* 이미지 압축 */
	float scale = (float)width / (image_info -> width);

	int element_height = (float)(image_info -> height) * scale;
	int element_width = width;

	Cell** image = new Cell*[element_height];
	for (int row = 0; row < element_height; row++) {
		image[row] = new Cell[element_width];
	}

	//여기서 가다가 세그폴트 뜸 아니 진짜 왜?? 아예 안돌아가는것도 아니고열몇번 돌다가 뜸;;
	for (int row = 0; row < element_height; row++) {
		for (int col = 0; col < element_width; col++) {
			cout << row << " " << col << endl;
			int nr = (float)row / scale;
			int nc = (float)col / scale;

			int red = image_info -> image[row][col].r;
			int green = image_info -> image[row][col].g;
			int blue = image_info -> image[row][col].b;
			int opacity = image_info -> image[row][col].a;
			
			if (opacity == 0 || red + green + blue > 700) {
				image[nr][nc].value = ' ';
				image[nr][nc].color = WHITE;
			} else {
				image[nr][nc].value = shape;
				if (red > 200 && green > 200 && blue > 200) {
					image[nr][nc].color = WHITE;
				} else if (red > 200) {
					image[nr][nc].color = RED;
				} else if (green > 200) {
					image[nr][nc].color = GREEN;
				} else if (blue > 200) {
					image[nr][nc].color = BLUE;
				} else {
					image[nr][nc].color = WHITE;
				}
			}
		}
	}

	//Element element(id, element_width, element_height, x, y, image);

	delete image_info;

	//return element;
}