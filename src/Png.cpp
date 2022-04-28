/*
 * Png.cpp
 *
 *      Author: Andreas Volz
 */

// Local
#include "Png.h"
#include "FileUtil.h"

// System
#include <cstring>
#include <stdlib.h>
#include <zlib.h>

Png::Png()
{
}

Png::~Png()
{

}

int Png::save(const std::string &name, PaletteImage &palImage, Palette &palette, int transparent)
{
  FILE *fp;
  png_structp png_ptr;
  png_infop info_ptr;
  unsigned char **lines;
  int i;

  std::shared_ptr<DataChunk> palData = palette.createDataChunk();
  unsigned char *pal = palData->getDataPointer();

  unsigned char *image = palImage.getRawDataPointer();

  CheckPath(name);

  if (!(fp = fopen(name.c_str(), "wb")))
  {
    printf("%s:", name.c_str());
    perror("Can't open file");
    fflush(stdout);
    fflush(stderr);
    return 1;
  }

  png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png_ptr)
  {
    fclose(fp);
    return 1;
  }
  info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr)
  {
    png_destroy_write_struct(&png_ptr, NULL);
    fclose(fp);
    return 1;
  }

  if (setjmp(png_jmpbuf(png_ptr)))
  {
    // FIXME: must free buffers!!
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
    return 1;
  }
  png_init_io(png_ptr, fp);

  // zlib parameters
  png_set_compression_level(png_ptr, Z_BEST_COMPRESSION);

  // prepare the file information
  png_set_IHDR(png_ptr, info_ptr, palImage.getSize().getWidth(), palImage.getSize().getHeight(), 8, PNG_COLOR_TYPE_PALETTE,
               0, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
  png_set_invalid(png_ptr, info_ptr, PNG_INFO_PLTE);
  png_set_PLTE(png_ptr, info_ptr, (png_colorp) pal, 256);

  if (transparent != -1)
  {
    png_byte trans[256];

    memset(trans, 0xFF, sizeof(trans));
    trans[transparent] = 0x0;
    png_set_tRNS(png_ptr, info_ptr, trans, 256, 0);
  }

  // write the file header information
  png_write_info(png_ptr, info_ptr);

  // set transformation

  // prepare image
  lines = (unsigned char **) malloc(palImage.getSize().getHeight() * sizeof(*lines));
  if (!lines)
  {
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
    return 1;
  }

  for (i = 0; i < palImage.getSize().getHeight(); ++i)
  {
    lines[i] = image + i * palImage.getSize().getWidth();
  }

  png_write_image(png_ptr, lines);
  png_write_end(png_ptr, info_ptr);

  png_destroy_write_struct(&png_ptr, &info_ptr);
  fclose(fp);

  free(lines);

  return 0;
}


int Png::saveRGBA(const std::string &name, PaletteImage &palImage, Palette &palette, int transparent)
{
  FILE *fp;
  png_structp png_ptr;
  png_infop info_ptr;
  png_bytep *row_pointers = NULL;
  const int RGBA_BYTE_SIZE = 4;
  const int RGB_BYTE_SIZE = 3;

  unsigned char *image = palImage.getRawDataPointer();

  std::shared_ptr<DataChunk> palData = palette.createDataChunk();
  unsigned char *pal = palData->getDataPointer();

  CheckPath(name);

  if (!(fp = fopen(name.c_str(), "wb")))
  {
    printf("%s:", name.c_str());
    perror("Can't open file");
    fflush(stdout);
    fflush(stderr);
    return 1;
  }

  png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png_ptr)
  {
    fclose(fp);
    return 1;
  }
  info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr)
  {
    png_destroy_write_struct(&png_ptr, NULL);
    fclose(fp);
    return 1;
  }

  if (setjmp(png_jmpbuf(png_ptr)))
  {
    // FIXME: must free buffers!!
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
    return 1;
  }
  png_init_io(png_ptr, fp);

  // zlib parameters
  png_set_compression_level(png_ptr, Z_BEST_COMPRESSION);

  // prepare the file information
  png_set_IHDR(png_ptr, info_ptr, palImage.getSize().getWidth(), palImage.getSize().getHeight(), 8, PNG_COLOR_TYPE_RGBA, 0, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

  // write the file header information
  png_write_info(png_ptr, info_ptr);

  row_pointers = (png_bytep *) malloc(sizeof(png_bytep) * palImage.getSize().getHeight());


  for (int h_pos = 0; h_pos < palImage.getSize().getHeight(); ++h_pos)
  {
    row_pointers[h_pos] = (unsigned char *) malloc(palImage.getSize().getWidth() * RGBA_BYTE_SIZE);

    unsigned char *img_line_pal = image + h_pos * palImage.getSize().getWidth();

    for (int w_pos = 0; w_pos < palImage.getSize().getWidth(); w_pos++)
    {
      unsigned char pal_pos = img_line_pal[w_pos];
      //printf("pal_pos (w:%d/h:%d) pal:%d\n", w_pos, h_pos,(int) pal_pos);

      unsigned char color_r = 0;
      unsigned char color_g = 0;
      unsigned char color_b = 0;
      unsigned char color_a = 0;

      if (pal_pos != 255)
      {
        color_r = pal[pal_pos * RGB_BYTE_SIZE + 0];
        color_g = pal[pal_pos * RGB_BYTE_SIZE + 1];
        color_b = pal[pal_pos * RGB_BYTE_SIZE + 2];
        color_a = transparent;
      }

      row_pointers[h_pos][w_pos * RGBA_BYTE_SIZE + 0] = color_r;
      row_pointers[h_pos][w_pos * RGBA_BYTE_SIZE + 1] = color_g;
      row_pointers[h_pos][w_pos * RGBA_BYTE_SIZE + 2] = color_b;
      row_pointers[h_pos][w_pos * RGBA_BYTE_SIZE + 3] = color_a;
    }

  }

  png_set_rows(png_ptr, info_ptr, row_pointers);
  png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);

  png_destroy_write_struct(&png_ptr, &info_ptr);
  fclose(fp);

  if (NULL != row_pointers)
  {
    for (int h_pos = 0; h_pos < palImage.getSize().getHeight(); ++h_pos)
    {
      free(row_pointers[h_pos]);
    }

    free(row_pointers);
    row_pointers = NULL;
  }

  return 0;
}

int Png::saveRGBA(const std::string &name, PaletteImage &palImage, Palette2D &palette2d, int transparent)
{
  FILE *fp;
  png_structp png_ptr;
  png_infop info_ptr;
  png_bytep *row_pointers = NULL;
  const int RGBA_BYTE_SIZE = 4;
  const int RGB_BYTE_SIZE = 3;

  unsigned char *image = palImage.getRawDataPointer();

  //std::shared_ptr<DataChunk> palData = palette.createDataChunk();
  //unsigned char *pal = palData->getDataPointer();

  CheckPath(name);

  if (!(fp = fopen(name.c_str(), "wb")))
  {
    printf("%s:", name.c_str());
    perror("Can't open file");
    fflush(stdout);
    fflush(stderr);
    return 1;
  }

  png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png_ptr)
  {
    fclose(fp);
    return 1;
  }
  info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr)
  {
    png_destroy_write_struct(&png_ptr, NULL);
    fclose(fp);
    return 1;
  }

  if (setjmp(png_jmpbuf(png_ptr)))
  {
    // FIXME: must free buffers!!
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
    return 1;
  }
  png_init_io(png_ptr, fp);

  // zlib parameters
  png_set_compression_level(png_ptr, Z_BEST_COMPRESSION);

  // prepare the file information
  png_set_IHDR(png_ptr, info_ptr, palImage.getSize().getWidth(), palImage.getSize().getHeight(), 8, PNG_COLOR_TYPE_RGBA, 0, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

  // write the file header information
  png_write_info(png_ptr, info_ptr);

  row_pointers = (png_bytep *) malloc(sizeof(png_bytep) * palImage.getSize().getHeight());

  for (int h_pos = 0; h_pos < palImage.getSize().getHeight(); ++h_pos)
  {
    row_pointers[h_pos] = (unsigned char *) malloc(palImage.getSize().getWidth() * RGBA_BYTE_SIZE);

    unsigned char *img_line_pal = image + h_pos * palImage.getSize().getWidth();

    for (int w_pos = 0; w_pos < palImage.getSize().getWidth(); w_pos++)
    {
      unsigned char pal_pos = img_line_pal[w_pos];
      unsigned char pal_beneath = 0;

      Color reference_beneath_color (0, 0, 0); // back palette id #0

      if(pal_pos != 255)
      {
        //printf("pal_pos (w:%d/h:%d) pal:%d\n", w_pos, h_pos,(int) pal_pos);
      }

      unsigned char color_r = 0;
      unsigned char color_g = 0;
      unsigned char color_b = 0;
      unsigned char color_a = 0;

      if (pal_pos != 255)
      {
        const Color &color_orig = palette2d.at(pal_beneath, pal_pos-1);
        Color color_bright = color_orig.getBrighened();

        double alpha_red = (double)(color_orig.getRed() - reference_beneath_color.getRed()) /
            (double) (color_bright.getRed() - reference_beneath_color.getRed());

        double alpha_green = (double) (color_orig.getGreen() - reference_beneath_color.getGreen()) /
            (double) (color_bright.getGreen() - reference_beneath_color.getGreen());

        double alpha_blue = (double) (color_orig.getBlue() - reference_beneath_color.getBlue()) /
            (double)(color_bright.getBlue() - reference_beneath_color.getBlue());


        double alpha = 0;

        // red biggest
        if((color_orig.getRed() > color_orig.getGreen()) &
           (color_orig.getRed() > color_orig.getBlue()))
        {
          alpha = (double) (color_orig.getRed() - reference_beneath_color.getRed()) /
                  (double) (color_bright.getRed() - reference_beneath_color.getRed());

        }
        // green is biggest
        else if((color_orig.getGreen() > color_orig.getRed()) &
                (color_orig.getGreen() > color_orig.getBlue()))
        {
          alpha = (double) (color_orig.getGreen() - reference_beneath_color.getGreen()) /
                  (double) (color_bright.getGreen() - reference_beneath_color.getGreen());
        }
        // blue is biggest
        {
          alpha = (double) (color_orig.getBlue() - reference_beneath_color.getBlue()) /
                  (double) (color_bright.getBlue() - reference_beneath_color.getBlue());
        }


        /*printf("alpha_red:%f\n", alpha_red);
        printf("alpha_green:%f\n", alpha_green);
        printf("alpha_blue:%f\n", alpha_blue);
        printf("alpha:%f\n", alpha);*/

        unsigned char red = alpha * color_orig.getRed() + (1 - alpha) * reference_beneath_color.getRed();
        unsigned char green = alpha * color_orig.getGreen() + (1 - alpha) * reference_beneath_color.getGreen();
        unsigned char blue = alpha * color_orig.getBlue() + (1 - alpha) * reference_beneath_color.getBlue();

        Color color_result (red, green, blue);

        color_r = color_result.getRed();
        color_g = color_result.getGreen();
        color_b = color_result.getBlue();
        color_a = alpha * 255;

        if((color_r == 16) && (color_g == 0) && (color_b == 0))
        {
          printf("c");
        }
      }

      row_pointers[h_pos][w_pos * RGBA_BYTE_SIZE + 0] = color_r;
      row_pointers[h_pos][w_pos * RGBA_BYTE_SIZE + 1] = color_g;
      row_pointers[h_pos][w_pos * RGBA_BYTE_SIZE + 2] = color_b;
      row_pointers[h_pos][w_pos * RGBA_BYTE_SIZE + 3] = color_a;
    }

  }

  png_set_rows(png_ptr, info_ptr, row_pointers);
  png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);

  png_destroy_write_struct(&png_ptr, &info_ptr);
  fclose(fp);

  if (NULL != row_pointers)
  {
    for (int h_pos = 0; h_pos < palImage.getSize().getHeight(); ++h_pos)
    {
      free(row_pointers[h_pos]);
    }

    free(row_pointers);
    row_pointers = NULL;
  }

  return 0;
}
