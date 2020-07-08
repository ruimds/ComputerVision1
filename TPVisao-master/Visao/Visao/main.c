#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include "vc.h"
int main()
{
	IVC *image[41];
	int i;
	int numero[8];
	OVC *nobjetos;
	OVC *nobjetos1;
	OVC *nobjetos2;
	OVC *nobjetos3;
	OVC *nobjetos4;
	OVC *nobjetos5;
	OVC *nobjetos6;
	OVC *nobjetos7;

	image[0] = vc_read_image("Imagens/Imagem01.ppm");
	if (image[0] == NULL)
	{
		printf("Error -> vc_read_image():\tFile not found.\n");
		getchar();
		return 0;
	}

	image[1] = vc_image_new(image[0]->width, image[0]->height,1, image[0]->levels);
	if (image[1] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}

	image[2] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[2] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}

	image[3] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[3] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}

	image[4] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[4] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}

	image[5] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[5] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	//imagens que sao usadas para as segmentações - São necessárias 5 imagens por cada ficha devido ás diversas funções que são utilizadas
	//imagens para a segmentação de peças brancas
	image[6] = vc_image_new(image[0]->width, image[0]->height, image[0]->channels, image[0]->levels);
	if (image[6] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[7] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[7] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[8] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[8] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[9] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[9] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[10] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[10] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	//imagens para segmentação de fichas vermelhas
	image[11] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[11] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[12] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[12] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[13] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[13] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[14] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[14] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}	
	image[15] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[15] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}

	//imagens para segmentação de fichas verdes
	image[16] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[16] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[17] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[17] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[18] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[18] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[19] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[19] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[20] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[20] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	//imagens para segmentação de fichas azuis
	image[21] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[21] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[22] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[22] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[23] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[23] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[24] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[24] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[25] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[25] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	//imagens para segmentação de fichas pretas
	image[26] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[26] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[27] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[27] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[28] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[28] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[29] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[29] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[30] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[30] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	//imagens para segmentação de fichas do tipo small blind
	image[31] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[31] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}	
	image[32] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[32] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}	
	image[33] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[33] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}	
	image[34] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[34] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}	
	image[35] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[35] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	//imagens para segmentação de fichas do tipo big blind
	image[36] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[36] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[37] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[37] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[38] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[38] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[39] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[39] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	image[40] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[40] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}
	//SEGMENTAÇÃO DO FUNDO PARA OBTER A QUANTIDADE DE OBJETOS NO TOTAL
	vc_rgb_to_hsv(image[0]);
	//vc_hsv_segmentation(image[0], 10, 229, 0, 95, 10, 100);
	//vc_hsv_segmentation(image[0], 10, 45, 10, 38, 55, 90);
	vc_rgb_to_gray(image[0], image[1]);
	vc_gray_negative(image[1]);
	vc_write_image("vc00015.ppm", image[1]);
	vc_binary_open(image[1], image[2], 5, 5);
	vc_binary_close(image[2], image[3],3, 3);

	nobjetos = vc_binary_blob_labelling(image[3], image[4], &numero[0]);
	vc_binary_blob_info(image[4], nobjetos, numero[0]);
	vc_write_image("vc0001.ppm", image[4]);
	vc_draw_image(nobjetos,image[4], numero[0]);

	//SEGMENTAÇÃO E CONTAGEM DE FICHAS BRANCAS
	vc_rgb_to_hsv(image[6]);
	vc_hsv_segmentation(image[6], 190, 201, 5, 9, 90, 95);
	vc_rgb_to_gray(image[6], image[7]);
	vc_gray_negative(image[7]);

	vc_binary_open(image[7], image[8], 5, 5);
	vc_binary_close(image[8], image[9], 3, 3);

	nobjetos1 = vc_binary_blob_labelling(image[9], image[10], &numero[1]);
	vc_binary_blob_info(image[10], nobjetos1, numero[1]);

	vc_write_image("vc00010.ppm", image[10]);
	vc_write_image("vc00011.ppm", image[9]);

	vc_image_free(image[6]);
	vc_image_free(image[7]);
	vc_image_free(image[8]);
	vc_image_free(image[9]);
	vc_image_free(image[10]);



	//SEGMENTAÇÃO E CONTAGEM DE FICHAS VERMELHAS
	vc_rgb_to_hsv(image[11]);
	vc_hsv_segmentation(image[11], 343, 353, 52, 58, 67, 73);
	vc_rgb_to_gray(image[11], image[12]);
	vc_gray_negative(image[12]);

	vc_binary_open(image[12], image[13], 5, 5);
	vc_binary_close(image[13], image[14], 3, 3);

	nobjetos2 = vc_binary_blob_labelling(image[14], image[15], &numero[2]);
	vc_binary_blob_info(image[15], nobjetos2, numero[2]);

	vc_image_free(image[11]);
	vc_image_free(image[12]);
	vc_image_free(image[13]);
	vc_image_free(image[14]);
	vc_image_free(image[15]);
	//SEGMENTAÇÃO E CONTAGEM DE FICHAS VERDES
	vc_rgb_to_hsv(image[16]);
	vc_hsv_segmentation(image[16], 186, 188, 90, 93, 60, 70);
	vc_rgb_to_gray(image[16], image[17]);
	vc_gray_negative(image[17]);

	vc_binary_open(image[17], image[18], 5, 5);
	vc_binary_close(image[18], image[19], 3, 3);

	nobjetos3 = vc_binary_blob_labelling(image[19], image[20], &numero[3]);
	vc_binary_blob_info(image[20], nobjetos3, numero[3]);

	vc_image_free(image[16]);
	vc_image_free(image[17]);
	vc_image_free(image[18]);
	vc_image_free(image[19]);
	vc_image_free(image[20]);
	//SEGMENTAÇÃO E CONTAGEM DE FICHAS AZUIS
	vc_rgb_to_hsv(image[21]);
	vc_hsv_segmentation(image[21], 216,218, 79, 88, 58, 64);
	vc_rgb_to_gray(image[21], image[22]);
	vc_gray_negative(image[22]);

	vc_binary_open(image[22], image[23], 5, 5);
	vc_binary_close(image[23], image[24], 3, 3);

	nobjetos4 = vc_binary_blob_labelling(image[24], image[25], &numero[4]);
	vc_binary_blob_info(image[25], nobjetos4, numero[4]);

	vc_image_free(image[21]);
	vc_image_free(image[22]);
	vc_image_free(image[23]);
	vc_image_free(image[24]);
	vc_image_free(image[25]);
	//SEGMENTAÇÃO E CONTAGEM DE FICHAS PRETAS
	vc_rgb_to_hsv(image[26]);
	vc_hsv_segmentation(image[26], 210, 213, 31, 38, 22, 29);
	vc_rgb_to_gray(image[26], image[27]);
	vc_gray_negative(image[27]);

	vc_binary_open(image[27], image[28], 5, 5);
	vc_binary_close(image[28], image[29], 3, 3);

	nobjetos5 = vc_binary_blob_labelling(image[29], image[30], &numero[5]);
	vc_binary_blob_info(image[30], nobjetos5, numero[5]);

	vc_image_free(image[26]);
	vc_image_free(image[27]);
	vc_image_free(image[28]);
	vc_image_free(image[29]);
	vc_image_free(image[30]);
	//SEGMENTAÇÃO E CONTAGEM DE FICHAS SMALL BLIND
	vc_rgb_to_hsv(image[31]);
	vc_hsv_segmentation(image[31], 248, 251, 43, 50, 64, 67);
	vc_rgb_to_gray(image[31], image[32]);
	vc_gray_negative(image[32]);

	vc_binary_open(image[32], image[33], 5, 5);
	vc_binary_close(image[33], image[34], 3, 3);

	nobjetos6 = vc_binary_blob_labelling(image[34], image[35], &numero[6]);
	vc_binary_blob_info(image[35], nobjetos6, numero[6]);

	vc_image_free(image[31]);
	vc_image_free(image[32]);
	vc_image_free(image[33]);
	vc_image_free(image[34]);
	vc_image_free(image[35]);
	//SEGMENTAÇÃO E CONTAGEM DE FICHAS BIG BLIND
	vc_rgb_to_hsv(image[36]);
	vc_hsv_segmentation(image[36], 48, 49, 39, 46, 90, 91);
	vc_rgb_to_gray(image[36], image[37]);
	vc_gray_negative(image[37]);

	vc_binary_open(image[37], image[38], 5, 5);
	vc_binary_close(image[38], image[39], 3, 3);

	nobjetos7 = vc_binary_blob_labelling(image[39], image[40], &numero[7]);
	vc_binary_blob_info(image[40], nobjetos7, numero[7]);

	vc_image_free(image[36]);
	vc_image_free(image[37]);
	vc_image_free(image[38]);
	vc_image_free(image[39]);
	vc_image_free(image[40]);

	//Diz o numero de objetos no total na imagem
	for (i = 0; i < numero[0]; i++)
	{
		printf("X = %d Y = %d Perimetro=%d Area=%d\n", nobjetos[i].x, nobjetos[i].y,nobjetos[i].perimeter, nobjetos[i].area);
		
	}
	printf("\n\n Numero de objetos no total = %d\n", numero[0]);
	
	//vc_color_finder(nobjetos, image[5], numero);

	//numero de fichas brancas
	for (i = 0; i < numero[1]; i++)
	{
		printf("X = %d Y = %d Perimetro=%d Area=%d\n", nobjetos1[i].x, nobjetos1[i].y, nobjetos1[i].perimeter, nobjetos1[i].area);

	}
	printf("\n\n Numero de objetos brancos = %d\n", numero[1]);

	//numero de fichas vermelhas
	for (i = 0; i < numero[2]; i++)
	{
		printf("X = %d Y = %d Perimetro=%d Area=%d\n", nobjetos2[i].x, nobjetos2[i].y, nobjetos2[i].perimeter, nobjetos2[i].area);

	}
	printf("\n\n Numero de objetos vermelhos = %d\n", numero[2]);

	//numero de fichas verdes
	for (i = 0; i < numero[3]; i++)
	{
		printf("X = %d Y = %d Perimetro=%d Area=%d\n", nobjetos3[i].x, nobjetos3[i].y, nobjetos3[i].perimeter, nobjetos3[i].area);

	}
	printf("\n\n Numero de objetos verdes = %d\n", numero[3]);

	//numero de fichas azuis
	for (i = 0; i < numero[4]; i++)
	{
		printf("X = %d Y = %d Perimetro=%d Area=%d\n", nobjetos4[i].x, nobjetos4[i].y, nobjetos4[i].perimeter, nobjetos4[i].area);

	}
	printf("\n\n Numero de objetos azuis = %d\n", numero[4]);

	//numero de fichas pretas
	for (i = 0; i < numero[5]; i++)
	{
		printf("X = %d Y = %d Perimetro=%d Area=%d\n", nobjetos5[i].x, nobjetos5[i].y, nobjetos5[i].perimeter, nobjetos5[i].area);

	}
	printf("\n\n Numero de objetos pretos = %d\n", numero[5]);

	//numero de fichas do tipo small blind
	for (i = 0; i < numero[6]; i++)
	{
		printf("X = %d Y = %d Perimetro=%d Area=%d\n", nobjetos6[i].x, nobjetos6[i].y, nobjetos6[i].perimeter, nobjetos6[i].area);

	}
	printf("\n\n Numero de objetos small blind = %d\n", numero[6]);

	//numero de fichas do tipo big blind
	for (i = 0; i < numero[7]; i++)
	{
		printf("X = %d Y = %d Perimetro=%d Area=%d\n", nobjetos7[i].x, nobjetos7[i].y, nobjetos7[i].perimeter, nobjetos7[i].area);

	}
	printf("\n\n Numero de objetos big blind = %d\n", numero[7]);
	vc_write_image("vc00023.ppm", image[3]);
	vc_write_image("vc0002.ppm", image[4]); 

	free(nobjetos);
	free(nobjetos1);
	free(nobjetos2);
	free(nobjetos3);
	free(nobjetos4);
	free(nobjetos5);
	free(nobjetos6);
	free(nobjetos7);

	vc_image_free(image[0]);
	vc_image_free(image[1]);
	vc_image_free(image[2]);
	vc_image_free(image[3]);
	vc_image_free(image[4]);
	vc_image_free(image[5]);

	


	system("cmd /c start FilterGear Imagens/Imagem01.ppm"); // Input
	system("FilterGear vc00023.ppm"); // Output
	system("FilterGear vc0001.ppm"); // Output
	system("FilterGear vc0002.ppm"); // Output
	system("FilterGear vc00010.ppm"); // Output
	system("FilterGear vc00011.ppm"); // Output
	system("FilterGear vc00015.ppm"); // Output

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;

}