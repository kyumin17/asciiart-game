#include <iostream>
#include "read.hpp"

#define COLOR_DEPTH 8

using namespace std;

bool readImage(char* file_name, ImageInfo* image_info) {
	/*
	if there is a problem reading the image, return false and return true otherwise
	get information of width, height, and rgb value of each pixel
	*/

	/* initialize and error handling */
	FILE *fp = fopen(file_name, "rb");
	png_structp png_ptr;
	png_infop info_ptr;
	if (!fp) {
		cout << "ERROR: could not read image " << file_name << endl;
		return false;
	}

	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) {
		cout << "ERROR: could not initialize png struct" << endl;
		return false;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr) {
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

	/* get information of image */
	int width = png_get_image_width(png_ptr, info_ptr);
	int height = png_get_image_height(png_ptr, info_ptr);
	int color_type = png_get_color_type(png_ptr, info_ptr);

	if (color_type == PNG_COLOR_TYPE_RGB) {
		png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER); //rgb to rgba
	} else if (color_type != PNG_COLOR_TYPE_RGB_ALPHA) {
		cout << "ERROR: invalid color type" << endl;
		return false;
	}

	png_read_update_info(png_ptr, info_ptr);

	png_bytep* row_pointers = (png_bytep *)malloc(sizeof(png_bytep) * height);
	for (int row  = 0; row < height; row++) {
		row_pointers[row] = (png_bytep)malloc(png_get_rowbytes(png_ptr, info_ptr));
	}

	png_read_image(png_ptr, row_pointers);

	/* write info in image_info */
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

	/* free memory */
	for (int row = 0; row < height; row++) {
		delete[] row_pointers[row];
	}
	delete[] row_pointers;

	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	fclose(fp);

	return true;
}

void compressImage(int com_width, ImageInfo* compress_image_info, ImageInfo* image_info) {
	/*
	reduce image size and write info to compress_image_info
	*/

	int height = image_info -> height;
	int width = image_info -> width;
	float scale = (float)width / com_width;

	/* write compression width and height */
	int com_height = height / scale;
	compress_image_info -> height = com_height;
	compress_image_info -> width = com_width;

	/* get compression image */
	compress_image_info -> image = new Pixel*[com_height];
	for (int row = 0; row < com_height; row++) {
		compress_image_info -> image[row] = new Pixel[com_width];
	}

	for (int row = 0; row < com_height; row++) {
		for (int col = 0; col < com_width; col++) {
			compress_image_info -> image[row][col] = image_info -> image[(int)((float)row * scale)][(int)((float)col * scale)];
		}
	}
}

void imageToElement(Element* element, Attr attr, char c, ImageInfo* image_info) {
	element -> width = image_info -> width;
	element -> height = image_info -> height;

	for (int row = 0; row < element -> height; row++) {
		for (int col = 0; col < element -> width; col++) {
			int red = image_info -> image[row][col].r;
			int green = image_info -> image[row][col].g;
			int blue = image_info -> image[row][col].b;
			int opacity = image_info -> image[row][col].a;

			if (opacity == 0 || red + green + blue > 200) { // 투명하거나 너무 연하면 fill X
				element -> image[row][col].attr = EMPTY;
				element -> image[row][col].value = ' ';
			} else {
				element -> image[row][col].attr = PLAYER;
				element -> image[row][col].value = c;
			}
		}
	}
}