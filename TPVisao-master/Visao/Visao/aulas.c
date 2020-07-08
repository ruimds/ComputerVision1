#include<stdio.h>
#include<stdlib.h>
#include"vc.h"

// Abrir imagem, alterar e gravar em novo ficheiro
int main_1(void) {
	IVC *image;
	int i;

	image = vc_read_image("C:/Users/asus/Desktop/Visao/Visao/Images/FLIR/flir-01.pgm");

	if (image == NULL) {
		printf("Error -> vc_read_image():\tFile not found.\n");
		getchar();
		return 0;
	}

	for (i = 0; i < image->bytesperline*image->height; i += image->channels) {
		image->data[i] = 255 - image->data[i];
	}

	vc_write_image("vc-0001.pgm",image);

	system("cmd /c start FilterGear Images/FLIR/flir-01.pgm");	// Input
	system("FilterGear vc-0001.pgm");	// Output

	vc_image_free(image);

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

// Criar uma imagem binária e gravar para ficheiro
int main_2(void)
{
	IVC *image;
	int x, y;
	long int pos;

	image = vc_image_new(320, 280, 1, 1);	// Cria nova imagem com 320 de largura, 280 de altura, 1 canal (Preto e branco ou tons de cinzento) e pode tomar valores 0 ou 1 (preto ou branco)
	// Verifica se a imagem existe
	if (image == NULL)
	{
		printf("ERROR -> vc_image_new():\n\tOut of memory!\n");
		getchar();
		return 0;
	}

	for (x = 0; x<image->width; x++)
	{
		for (y = 0; y<image->height; y++)
		{
			pos = y * image->bytesperline + x * image->channels;

			// Se o x for menor ou igual a metade da largura e y menor ou igual a metade da altura, toma valor 1 (branco)
			if ((x <= image->width/2) && (y <= image->height/2)) image->data[pos] = 1;
			// Se o x for maior que metade da largura e y maior que metade da altura, toma valor 1 (branco)
			else if ((x > image->width/2) && (y > image->height/2)) image->data[pos] = 1;
			// Caso contrário toma valor 0 (preto)
			else image->data[pos] = 0;
		}
	}
	// Guarda a imagem como pbm (binária)
	vc_write_image("teste.pbm", image);

	vc_image_free(image);

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

// Ler uma imagem binária, alterar e gravar em novo ficheiro
int main_3(void)
{
	IVC *image;
	int i;

	image = vc_read_image("teste.pbm");
	if (image == NULL)
	{
		printf("ERROR -> vc_read_image():\n\tFile not found!\n");
		getchar();
		return 0;
	}

	// Percorre a imagem e inverte
	for (i = 0; i < image->bytesperline*image->height; i += image->channels) 
	{
		if (image->data[i] == 1) image->data[i] = 0;
		else image->data[i] = 1;
	}

	vc_write_image("teste2.pbm", image);

	vc_image_free(image);

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								Exercício para resolução 256 x 256
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main_4(void) 
{
	IVC *image;
	int x, y;
	long int pos;

	image = vc_image_new(256, 256, 1, 255);
	// Verifica se a imagem existe
	if (image == NULL)
	{
		printf("ERROR -> vc_image_new():\n\tOut of memory!\n");
		getchar();
		return 0;
	}

	for (x = 0; x < image->width; x++) 
	{
		for (y = 0; y < image->height; y++) 
		{
			pos = y * image->bytesperline + x * image->channels;

			image->data[pos] = x;
		}
	}

	vc_write_image("exercicio1.pbm", image);

	vc_image_free(image);

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

int main_5(void)
{
	IVC *image;
	int x, y;
	long int pos;

	image = vc_image_new(256, 256, 1, 255);
	// Verifica se a imagem existe
	if (image == NULL)
	{
		printf("ERROR -> vc_image_new():\n\tOut of memory!\n");
		getchar();
		return 0;
	}

	for (x = 0; x < image->width; x++)
	{
		for (y = 0; y < image->height; y++)
		{
			pos = y * image->bytesperline + x * image->channels;

			image->data[pos] = y;
		}
	}

	vc_write_image("exercicio2.pbm", image);

	vc_image_free(image);

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

int main_6(void)
{
	IVC *image;
	int x, y;
	long int pos;

	image = vc_image_new(256, 256, 1, 255);
	// Verifica se a imagem existe
	if (image == NULL)
	{
		printf("ERROR -> vc_image_new():\n\tOut of memory!\n");
		getchar();
		return 0;
	}

	for (x = 0; x < image->width; x++)
	{
		for (y = 0; y < image->height; y++)
		{
			pos = y * image->bytesperline + x * image->channels;

			image->data[pos] = (x + y) / 2;
		}
	}

	vc_write_image("exercicio3.pbm", image);

	vc_image_free(image);

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//							Mesmo exercíco mas para 512 x 512
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main_7(void)
{
	IVC *image;
	int x, y;
	long int pos;

	image = vc_image_new(512, 512, 1, 255);
	// Verifica se a imagem existe
	if (image == NULL)
	{
		printf("ERROR -> vc_image_new():\n\tOut of memory!\n");
		getchar();
		return 0;
	}

	
	for (x = 0; x < image->width; x++)
	{
		for (y = 0; y < image->height; y++)
		{
			pos = y * image->bytesperline + x * image->channels;

			image->data[pos] = ((float) x / (float) image->width) * 255;
		}
	}

	vc_write_image("desafio1.pbm", image);

	vc_image_free(image);

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

int main_8(void)
{
	IVC *image;
	int x, y;
	long int pos;

	image = vc_image_new(512, 512, 1, 255);
	// Verifica se a imagem existe
	if (image == NULL)
	{
		printf("ERROR -> vc_image_new():\n\tOut of memory!\n");
		getchar();
		return 0;
	}

	for (x = 0; x < image->width; x++)
	{
		for (y = 0; y < image->height; y++)
		{
			pos = y * image->bytesperline + x * image->channels;

			image->data[pos] = ((float)y / (float)image->width) * 255;
		}
	}

	vc_write_image("desafio2.pbm", image);

	vc_image_free(image);

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}


int main_9(void)
{
	IVC *image;
	int x, y;
	long int pos;

	image = vc_image_new(512, 512, 1, 255);
	// Verifica se a imagem existe
	if (image == NULL)
	{
		printf("ERROR -> vc_image_new():\n\tOut of memory!\n");
		getchar();
		return 0;
	}

	for (x = 0; x < image->width; x++)
	{
		for (y = 0; y < image->height; y++)
		{
			pos = y * image->bytesperline + x * image->channels;

			image->data[pos] = (((float)x / (float)image->width) * 255 + ((float)y / (float)image->width) * 255) / 2;
		}
	}

	vc_write_image("desafio3.pbm", image);

	vc_image_free(image);

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

// Abrir uma imagem em grayscale, fazer negativo e gravar em novo ficheiro
int main_10(void) 
{
	IVC *image;

	image = vc_read_image("C:/Users/asus/Desktop/Visao/Visao/Images/FLIR/flir-01.pgm");
	if (image == NULL) 
	{
		printf("Error -> vc_read_image():\tFile not found.\n");
		getchar();
		return 0;
	}

	vc_gray_negative(image);

	vc_write_image("vc0007.pgm", image);

	vc_image_free(image);

	system("cmd /c start FilterGear Images/FLIR/flir-01.pgm"); // Input
	system("FilterGear vc0007.pgm"); // Output

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

// Abrir uma imagem em RGB, fazer negativo e gravar em novo ficheiro
int main_11(void)
{
	IVC *image;

	image = vc_read_image("C:/Users/asus/Desktop/Visao/Visao/Images/FLIR/flir-01.pgm");
	if (image == NULL)
	{
		printf("Error -> vc_read_image():\tFile not found.\n");
		getchar();
		return 0;
	}

	vc_rgb_negative(image);

	vc_write_image("vc0008.pgm", image);

	vc_image_free(image);

	system("cmd /c start FilterGear Images/FLIR/flir-01.pgm"); // Input
	system("FilterGear vc0008.pgm"); // Output

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

// Abre uma imagem em RGB, retira a componente RED e guarda em gray
int main_12(void)
{
	IVC *image;

	image = vc_read_image("C:/Users/asus/Desktop/Visao/Visao/Images/Classic/barbara.ppm");
	if (image == NULL)
	{
		printf("Error -> vc_read_image():\tFile not found.\n");
		getchar();
		return 0;
	}

	vc_rgb_negative(image);

	vc_write_image("vc0009.pgm", image);

	vc_image_free(image);

	system("cmd /c start FilterGear Images/Classic/barbara.ppm"); // Input
	system("FilterGear vc0009.pgm"); // Output

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

// Transforma imagem em RGB para GRAY
int main_13(void)
{
	IVC *image[2];

	image[0] = vc_read_image("C:/Users/asus/Desktop/Visao/Visao/Images/Classic/barbara.ppm");
	if (image[0] == NULL)
	{
		printf("Error -> vc_read_image():\tFile not found.\n");
		getchar();
		return 0;
	}

	image[1] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[1] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}

	vc_rgb_to_gray(image[0], image[1]);

	vc_write_image("vc00010.pgm", image[1]);

	vc_image_free(image[0]);
	vc_image_free(image[1]);

	system("cmd /c start FilterGear Images/Classic/barbara.ppm"); // Input
	system("FilterGear vc00010.pgm"); // Output

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

int main_14(void) 
{
	IVC *image, *imageGray;

	image = vc_read_image("Images/HSVTestImage01.ppm");
	if (image == NULL)
	{
		printf("Error -> vc_read_image():\tFile not found.\n");
		getchar();
		return 0;
	}

	// Vai buscar parametros à 'image' menos os canais porque queremos apenas um e a outra está em 3
	imageGray = vc_image_new(image->width, image->height, 1, image->levels);
	if (imageGray == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}

	vc_rgb_to_hsv(image);
	vc_hsv_segmentation(image, 210, 250, 85, 100, 70, 100);
	vc_rgb_to_gray(image, imageGray);

	vc_write_image("vc0013.pgm", imageGray);

	vc_image_free(image);
	vc_image_free(imageGray);

	system("cmd /c start FilterGear Images/HSVTestImage01.ppm"); // Input
	system("FilterGear vc0013.pgm"); // Output

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}


int main_15(void)
{
	IVC *image[2];

	image[0] = vc_read_image("C:/Users/asus/Desktop/Visao/Visao/Images/FLIR/flir-08.pgm");
	if (image[0] == NULL)
	{
		printf("Error -> vc_read_image():\tFile not found.\n");
		getchar();
		return 0;
	}

	image[1] = vc_image_new(image[0]->width, image[0]->height, 3, image[0]->levels);
	if (image[1] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}

	vc_scale_gray_to_rgb(image[0], image[1]);

	vc_write_image("vc00015.ppm", image[1]);

	vc_image_free(image[0]);
	vc_image_free(image[1]);

	system("cmd /c start FilterGear Images/FLIR/flir-08.pgm"); // Input
	system("FilterGear vc00015.ppm"); // Output

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}       

int main_16(void)
{
	IVC *image;

	image = vc_read_image("C:/Users/asus/Desktop/Visao/Visao/Images/FLIR/flir-01.pgm");
	if (image == NULL)
	{
		printf("Error -> vc_read_image():\tFile not found.\n");
		getchar();
		return 0;
	}

	vc_gray_to_binary(image, 150);

	vc_write_image("vc00016.pgm", image);

	vc_image_free(image);

	system("cmd /c start FilterGear Images/FLIR/flir-01.pgm"); // Input
	system("FilterGear vc00016.pgm"); // Output

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

int main_17(void)
{
	IVC *image;

	image = vc_read_image("C:/Users/asus/Desktop/Visao/Visao/ImagensTesteSegmentação/cells.pgm");
	if (image == NULL)
	{
		printf("Error -> vc_read_image():\tFile not found.\n");
		getchar();
		return 0;
	}

	vc_gray_to_binary_global_mean(image);

	vc_write_image("vc00017.pgm", image);

	vc_image_free(image);

	system("cmd /c start FilterGear ImagensTesteSegmentação/cells.pgm"); // Input
	system("FilterGear vc00017.pgm"); // Output

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

int main_18(void)
{
	IVC *image[2];

	image[0] = vc_read_image("C:/Users/asus/Desktop/Visao/Visao/ImagensTesteSegmentação/cells.pgm");
	if (image == NULL)
	{
		printf("Error -> vc_read_image():\tFile not found.\n");
		getchar();
		return 0;
	}

	image[1] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[1] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}

	vc_gray_to_binary_midpoint(image[0], image[1], 25);

	vc_write_image("vc00018.pgm", image[1]);

	vc_image_free(image[0]);
	vc_image_free(image[1]);

	system("cmd /c start FilterGear ImagensTesteSegmentação/cells.pgm"); // Input
	system("FilterGear vc00018.pgm"); // Output

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

int main_19(void)
{
	IVC *image[2];

	image[0] = vc_read_image("C:/Users/asus/Desktop/Visao/Visao/Images/FLIR/flir-01.pgm");
	if (image[0] == NULL)
	{
		printf("Error -> vc_read_image():\tFile not found.\n");
		getchar();
		return 0;
	}

	image[1] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[1] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}

	vc_gray_to_binary(image[0], 127);
	vc_binary_erode(image[0], image[1], 3);
	vc_binary_dilate(image[1], image[0], 3);

	vc_write_image("vc00020.pgm", image[1]);

	vc_image_free(image[0]);
	vc_image_free(image[1]);

	system("cmd /c start FilterGear vc00019.pgm"); // Input
	system("FilterGear vc00020.pgm"); // Output

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

int main_20(void)
{
	IVC *image[2];

	image[0] = vc_read_image("C:/Users/asus/Desktop/Visao/Visao/Images/FLIR/flir-01.pgm");
	if (image[0] == NULL)
	{
		printf("Error -> vc_read_image():\tFile not found.\n");
		getchar();
		return 0;
	}

	image[1] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
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

	vc_gray_to_binary(image[0], 127);
	vc_write_image("vc00021.pgm", image[0]);
	vc_binary_close(image[0], image[1], 3, 3);
	vc_binary_open(image[1], image[2], 3, 3);
	vc_write_image("vc00022.pgm", image[2]);

	vc_image_free(image[0]);
	vc_image_free(image[1]);
	vc_image_free(image[2]);

	system("cmd /c start FilterGear vc00021.pgm"); // Input
	system("FilterGear vc00022.pgm"); // Output

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

int main_21(void)
{
	IVC *image[2];
	int i, numero = 2;
	OVC *nobjetos;

	image[0] = vc_read_image("ImagensTesteSegmentação/coins.pgm");
	if (image[0] == NULL)
	{
		printf("Error -> vc_read_image():\tFile not found.\n");
		getchar();
		return 0;
	}

	image[1] = vc_image_new(image[0]->width, image[0]->height, 1, image[0]->levels);
	if (image[1] == NULL)
	{
		printf("Error -> vc_image_new():\tFail to create file.\n");
		getchar();
		return 0;
	}

	vc_gray_to_binary(image[0], 127);
	vc_gray_negative(image[0]);
	vc_binary_close(image[0], image[1], 5, 5);
	nobjetos = vc_binary_blob_labelling(image[1], image[0], &numero);
	vc_binary_blob_info(image[0], nobjetos, numero);
	for (i = 0; i < numero; i++) 
	{
		printf("X = %d Y = %d\n", nobjetos[i].x, nobjetos[i].y);
	}
	printf("\n\n Numero de objetos = %d", numero);

	vc_write_image("vc00023.pgm", image[0]);

	free(nobjetos);
	vc_image_free(image[0]);
	vc_image_free(image[1]);

	system("cmd /c start FilterGear ImagensTesteSegmentação/coins.pgm"); // Input
	system("FilterGear vc00023.pgm"); // Output

	printf("\nPress any key to exit.\n");
	getchar();
	return 0;
}

int main123()
{
	IVC* image;
	image = vc_read_image("Images/histograma/barbara2.pgm");
	if (image == NULL)
	{
		printf("Error -> vc_read_image():\tFile not found.\n");
		getchar();
		return 0;
	}
	vc_gray_histogram_equalization(image);
	vc_write_image("vc00024.pgm",image);

	system("cmd /c start FilterGear Images/histograma/barbara2.pgm"); // Input
	system("FilterGear vc00024.pgm"); // Output
}