//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//           INSTITUTO POLIT�CNICO DO C�VADO E DO AVE          +
//                          2011/2012                          +
//             ENGENHARIA DE SISTEMAS INFORM�TICOS             + 
//                    VIS�O POR COMPUTADOR                     +
//                                                             +
//             [  DUARTE DUQUE - dduque@ipca.pt  ]             +
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#define VC_DEBUG


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								MACROS                   
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

				// Se a > b, define m�ximo 'a' sen�o (:) define b
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                   ESTRUTURA DE UMA IMAGEM                   +
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


typedef struct {
	unsigned char *data;
	int width, height;
	int channels;			// Bin�rio/Cinzentos=1; RGB=3
	int levels;				// Bin�rio=1; Cinzentos [1,255]; RGB [1,255]
	int bytesperline;		// width * channels
} IVC;

typedef struct {
	int x, y, width, height;	// Caixa Delimitadora (Bounding Box)
	int area;					// �rea
	int xc, yc;					// Centro-de-massa
	int perimeter;				// Per�metro
	int label;					// Etiqueta
} OVC;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                    PROT�TIPOS DE FUN��ES                    +
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// FUN��ES: ALOCAR E LIBERTAR UMA IMAGEM
IVC *vc_image_new(int width, int height, int channels, int levels);
IVC *vc_image_free(IVC *image);

// FUN��ES: LEITURA E ESCRITA DE IMAGENS (PBM, PGM E PPM)
IVC *vc_read_image(char *filename);
int vc_write_image(char *filename, IVC *image);

// FUN��O QUE CALCULA O NEGATIVO DE UMA IMAGEM GRAY
int vc_gray_negative(IVC *srcdst);

// FUN��O QUE CALCULA O NEGATIVO DE UMA IMAGEM RGB
int vc_rgb_negative(IVC *srcdst);

// FUN��O PARA EXTRAIR UMA COMPONENTE DA IMAGEM RGB PARA GRAY
int vc_rgb_get_red_gray(IVC *srcdst); // Red
int vc_rgb_get_green_gray(IVC *srcdst);	// Green
int vc_rgb_get_blue_gray(IVC *srcdst);	// Blue

// FUN��O PARA CONVERTER DE RGB PARA GRAY
int vc_rgb_to_gray(IVC *src, IVC *dst);

// FUN��O PARA CONVERTER UMA IMAGEM NO ESPA�O RGB PARA O ESPA�O HSV
int vc_rgb_to_hsv(IVC *srcdst);
int vc_hsv_segmentation(IVC *srcdst, int hmin, int hmax, int smin, int smax, int vmin, int vmax);

// FUN��O PARA CONVERTER DE TONS DE CINZENTO PARA RGB
int vc_scale_gray_to_rgb(IVC *src, IVC *dst);

// FUN��ES PARA CONVERTER IMAGENS EM TONS DE CINZENTO PARA BIN�RIO
int vc_gray_to_binary(IVC *srcdst, int threshold);
int vc_gray_to_binary_global_mean(IVC *srcdst);

// FUN��O PARA 
int vc_gray_to_binary_midpoint(IVC *src, IVC *dst, int tamKernel);

// FUN��ES PARA EFETUAR DILATA��O E EROS�O
int vc_binary_dilate(IVC *src, IVC *dst, int kernel);
int vc_binary_erode(IVC *src, IVC *dst, int kernel);

// FUN��ES PARA FAZER ABERTURA E FECHO BIN�RIO
int vc_binary_open(IVC *src, IVC *dst, int sizeerode, int sizedilate);
int vc_binary_close(IVC *src, IVC *dst, int sizedilate, int sizeerode);

OVC* vc_binary_blob_labelling(IVC *src, IVC *dst, int *nlabels);
int vc_binary_blob_info(IVC *src, OVC *blobs, int nblobs);

//EQUALIZA��O DO HISTOGRAMA
int vc_gray_histogram_equalization(IVC *srcdst);

//Fun��o para desenhar
int vc_draw_image(OVC* blobs, IVC *src,int nblobs);
//fun��o para encontrar as cores
int vc_color_finder(OVC *blobs, IVC *src, int nblobs);