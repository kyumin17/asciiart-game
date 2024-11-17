#include <iostream>
#include "convert-img.hpp"

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

void makeElement() {

}