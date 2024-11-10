#include <iostream>
#include "image.hpp"

#define COLOR_DEPTH 8

using namespace std;

Image::Image(const char* file_name) {
	fn = file_name;
}

ImageInfo* Image::readImage() {
	/*
	if there is a problem reading the image, return false and return true otherwise
	get information of width, height, and rgb value of each pixel
	*/

	ImageInfo* image_info = new ImageInfo;

	/* initialize and error handling */
	FILE *fp = fopen(fn, "rb");
	png_structp png_ptr;
	png_infop info_ptr;
	if (!fp) {
		cout << "ERROR: could not read image " << fn << endl;
	}

	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) {
		cout << "ERROR: could not initialize png struct" << endl;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr) {
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		fclose(fp);
	}

	if (setjmp(png_jmpbuf(png_ptr))) {
		cout << "ERROR: could not init png" << endl;
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		fclose(fp);
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

	return image_info;
}

ImageInfo* Image::compressImage(int width) {
	/*
	reduce image size and write info to compress_image_info
	*/
	ImageInfo* image_info = new ImageInfo;
	image_info = readImage();
	ImageInfo* compress_image_info = new ImageInfo;

	int prev_height = image_info -> height;
	int prev_width = image_info -> width;
	float scale = (float)prev_width / width;

	/* write compression width and height */
	int height = prev_height / scale;
	compress_image_info -> height = height;
	compress_image_info -> width = width;

	/* get compression image */
	compress_image_info -> image = new Pixel*[height];
	for (int row = 0; row < height; row++) {
		compress_image_info -> image[row] = new Pixel[width];
	}

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			compress_image_info -> image[row][col] = image_info -> image[(int)((float)row * scale)][(int)((float)col * scale)];
		}
	}

	delete image_info;

	return compress_image_info;
}

Element* Image::imageToElement(int width, Attr attr, char c) {
	ImageInfo* image_info = compressImage(width);
	Element* element = new Element;

	element -> width = image_info -> width;
	element -> height = image_info -> height;

	for (int row = 0; row < element -> height; row++) {
		for (int col = 0; col < element -> width; col++) {
			int red = image_info -> image[row][col].r;
			int green = image_info -> image[row][col].g;
			int blue = image_info -> image[row][col].b;
			int opacity = image_info -> image[row][col].a;

			if (opacity == 0 || red + green + blue > 700) {
				element -> image[row][col].value = ' ';
				element -> image[row][col].attr = EMPTY;
				element -> image[row][col].color = WHITE;
			} else {
				element -> image[row][col].value = c;
				element -> image[row][col].attr = attr;
				if (red > 200 && green > 200 && blue > 200) {
					element -> image[row][col].color = WHITE;
				} else if (red > 200) {
					element -> image[row][col].value = RED;
				} else if (green > 200) {
					element -> image[row][col].value = GREEN;
				} else if (blue > 200) {
					element -> image[row][col].value = BLUE;
				}
			}
		}
	}

	delete image_info;
	
	return element;
}