/* Includes ------------------------------------------------------------------*/
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "imagedata.h"
#include <stdlib.h>

/* Entry point ----------------------------------------------------------------*/
void setup()
{
  printf("EPD_2IN13BC_test Demo\r\n");
  DEV_Module_Init();

  printf("e-Paper Init and Display 'LYB love LMX'...\r\n");
  EPD_2IN13BC_Init();
  DEV_Delay_ms(500);

  // Create a new image cache named IMAGE_BW and fill it with white
  UBYTE *BlackImage, *RYImage; // Red or Yellow
  UWORD Imagesize = ((EPD_2IN13BC_WIDTH % 8 == 0) ? (EPD_2IN13BC_WIDTH / 8 ) : (EPD_2IN13BC_WIDTH / 8 + 1)) * EPD_2IN13BC_HEIGHT;
  if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
    printf("Failed to apply for black memory...\r\n");
    while (1);
  }
  if ((RYImage = (UBYTE *)malloc(Imagesize)) == NULL) {
    printf("Failed to apply for red memory...\r\n");
    while (1);
  }
  printf("NewImage: BlackImage and RYImage\r\n");
  Paint_NewImage(BlackImage, EPD_2IN13BC_WIDTH, EPD_2IN13BC_HEIGHT, 270, WHITE);
  Paint_NewImage(RYImage, EPD_2IN13BC_WIDTH, EPD_2IN13BC_HEIGHT, 270, WHITE);

  // Select Image
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);
  Paint_SelectImage(RYImage);
  Paint_Clear(WHITE);

  printf("Draw 'LYB love LMX' on the screen\r\n");

  // Draw 'LYB love LMX' on the Black image
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);
  Paint_DrawString_EN(0, 20, "LYB love LMX", &Font24, WHITE, BLACK);  // Use Font24 for 'LYB love LMX'
  Paint_DrawString_EN(0, 40, "LYB love LMX", &Font24, WHITE, BLACK);  // Use Font24 for 'LYB love LMX'
  Paint_DrawString_EN(0, 60, "LYB love LMX", &Font24, WHITE, BLACK);  // Use Font24 for 'LYB love LMX'
  Paint_DrawString_EN(0, 80, "LYB love LMX", &Font24, WHITE, BLACK);  // Use Font24 for 'LYB love LMX'
  Paint_DrawString_EN(0, 100, "LYB love LMX", &Font24, WHITE, BLACK);  // Use Font24 for 'LYB love LMX'
  Paint_DrawString_EN(0, 120, "LYB love LMX", &Font24, WHITE, BLACK);  // Use Font24 for 'LYB love LMX'
//   Paint_DrawString_EN(0, 60, "uvwq", &Font24, WHITE, BLACK);  // Use Font24 for 'LYB love LMX'
  // Optional: Draw 'LYB love LMX' on the Red/Yellow image for a two-tone effect
  // Paint_SelectImage(RYImage);
  // Paint_Clear(WHITE);
  // Paint_DrawString_EN(20, 60, "LYB love LMX", &Font24, WHITE, RED);  // Red 'LYB love LMX' in Font24

  printf("EPD_Display\r\n");
  EPD_2IN13BC_Display(BlackImage, RYImage);

  // Free memory without clearing the display to keep 'LYB love LMX' on screen
  free(BlackImage);
  free(RYImage);
  BlackImage = NULL;
  RYImage = NULL;
}

/* The main loop -------------------------------------------------------------*/
void loop()
{
  // No additional actions needed to retain 'LYB love LMX' display
}

// /* Includes ------------------------------------------------------------------*/
// #include "DEV_Config.h"
// #include "EPD.h"
// #include "GUI_Paint.h"
// #include "imagedata.h"
// #include <stdlib.h>

// /* Entry point ----------------------------------------------------------------*/
// void setup()
// {
//   printf("EPD_2IN13BC_test Demo\r\n");
//   DEV_Module_Init();

//   printf("e-Paper Init and Display Image...\r\n");
//   EPD_2IN13BC_Init();
//   DEV_Delay_ms(500);

//   // Create a new image cache for Black and Red/Yellow images
//   UBYTE *BlackImage, *RYImage;
//   UWORD Imagesize = ((EPD_2IN13BC_WIDTH % 8 == 0) ? (EPD_2IN13BC_WIDTH / 8 ) : (EPD_2IN13BC_WIDTH / 8 + 1)) * EPD_2IN13BC_HEIGHT;
//   if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
//     printf("Failed to apply for black memory...\r\n");
//     while (1);
//   }
//   if ((RYImage = (UBYTE *)malloc(Imagesize)) == NULL) {
//     printf("Failed to apply for red/yellow memory...\r\n");
//     while (1);
//   }
//   printf("NewImage: BlackImage and RYImage\r\n");
//   Paint_NewImage(BlackImage, EPD_2IN13BC_WIDTH, EPD_2IN13BC_HEIGHT/2, 270, WHITE);
//   Paint_NewImage(RYImage, EPD_2IN13BC_WIDTH, EPD_2IN13BC_HEIGHT/2, 270, WHITE);

//   // Display the image from imagedata.h without clearing afterward
//   printf("Displaying image from imagedata.h\r\n");
//   EPD_2IN13BC_Display(gImage_2in13c_b, gImage_2in13c_y);  // Display the image defined in imagedata.h
//   DEV_Delay_ms(2000);

//   // Free memory without clearing the display to keep the image on screen
//   free(BlackImage);
//   free(RYImage);
//   BlackImage = NULL;
//   RYImage = NULL;
// }

// /* The main loop -------------------------------------------------------------*/
// void loop()
// {
//   // No additional actions needed to retain image display
// }


// /* Includes ------------------------------------------------------------------*/
// #include "DEV_Config.h"
// #include "EPD.h"
// #include "GUI_Paint.h"
// #include "imagedata.h"
// #include <stdlib.h>

// /* Entry point ----------------------------------------------------------------*/
// void setup()
// {
//   printf("EPD_2IN13BC_test Demo\r\n");
//   DEV_Module_Init();

//   printf("e-Paper Init and Clear...\r\n");
//   EPD_2IN13BC_Init();
//   EPD_2IN13BC_Clear();
//   DEV_Delay_ms(500);

//   //Create a new image cache named IMAGE_BW and fill it with white
//   UBYTE *BlackImage, *RYImage; // Red or Yellow
//   UWORD Imagesize = ((EPD_2IN13BC_WIDTH % 8 == 0) ? (EPD_2IN13BC_WIDTH / 8 ) : (EPD_2IN13BC_WIDTH / 8 + 1)) * EPD_2IN13BC_HEIGHT;
//   if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
//     printf("Failed to apply for black memory...\r\n");
//     while (1);
//   }
//   if ((RYImage = (UBYTE *)malloc(Imagesize)) == NULL) {
//     printf("Failed to apply for red memory...\r\n");
//     while (1);
//   }
//   printf("NewImage:BlackImage and RYImage\r\n");
//   Paint_NewImage(BlackImage, EPD_2IN13BC_WIDTH, EPD_2IN13BC_HEIGHT, 270, WHITE);
//   Paint_NewImage(RYImage, EPD_2IN13BC_WIDTH, EPD_2IN13BC_HEIGHT, 270, WHITE);

//   //Select Image
//   Paint_SelectImage(BlackImage);
//   Paint_Clear(WHITE);
//   Paint_SelectImage(RYImage);
//   Paint_Clear(WHITE);

// #if 1   // show image for array    
//   printf("show image for array\r\n");
//   //    EPD_2IN13BC_Display(gImage_2in13b_b, gImage_2in13b_r);

//   EPD_2IN13BC_Display(gImage_2in13c_b, gImage_2in13c_y);
//   DEV_Delay_ms(2000);
// #endif

// #if 1   // Drawing on the image
//   /*Horizontal screen*/
//   //1.Draw black image
//   printf("Draw black image\r\n");
//   Paint_SelectImage(BlackImage);
//   Paint_Clear(WHITE);
//   Paint_DrawPoint(5, 70, BLACK, DOT_PIXEL_1X1, DOT_STYLE_DFT);
//   Paint_DrawPoint(5, 80, BLACK, DOT_PIXEL_2X2, DOT_STYLE_DFT);
//   Paint_DrawLine(20, 70, 50, 100, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
//   Paint_DrawLine(50, 70, 20, 100, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
//   Paint_DrawRectangle(60, 70, 90, 100, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
//   Paint_DrawCircle(125, 85, 15, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
//   Paint_DrawString_CN(5, 15, "你好abc", &Font12CN, WHITE, BLACK);

//   //2.Draw red image
//   printf("Draw red image\r\n");
//   Paint_SelectImage(RYImage);
//   Paint_Clear(WHITE);
//   Paint_DrawPoint(5, 90, RED, DOT_PIXEL_3X3, DOT_STYLE_DFT);
//   Paint_DrawPoint(5, 100, RED, DOT_PIXEL_4X4, DOT_STYLE_DFT);
//   Paint_DrawLine(125, 70, 125, 100, RED, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
//   Paint_DrawLine(110, 85, 140, 85, RED, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
//   Paint_DrawRectangle(20, 70, 50, 100, RED, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
//   Paint_DrawCircle(165, 85, 15, RED, DOT_PIXEL_1X1, DRAW_FILL_FULL);
//   Paint_DrawString_EN(5, 0, "waveshare Electronics", &Font12, BLACK, WHITE);
//   Paint_DrawNum(5, 50, 987654321, &Font16, WHITE, RED);

//   printf("EPD_Display\r\n");
//   EPD_2IN13BC_Display(BlackImage, RYImage);
//   DEV_Delay_ms(2000);
// #endif

//   printf("Clear...\r\n");
//   EPD_2IN13BC_Clear();

//   printf("Goto Sleep...\r\n");
//   EPD_2IN13BC_Sleep();
//   free(BlackImage);
//   free(RYImage);
//   BlackImage = NULL;
//   RYImage = NULL;


// }

// /* The main loop -------------------------------------------------------------*/
// void loop()
// {
//   //
// }

