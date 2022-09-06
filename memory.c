#include "stdio.h"
#include "string.h"
#include "malloc.h"

#define STX 0x02
#define ETX 0x03

int txSerial(unsigned char *buffer, int size)
{
 return -1;
}

int txData(char *data)
{
 unsigned char *ptr = NULL, *buf = NULL;
 int size = strlen(data);

 /* allocate buffer */
 if ((ptr = buf = (unsigned char *)malloc(size + 3)) == NULL)
  return (-1);

 /* STX */
 *ptr++ = STX;

 /* data */
 strncpy(ptr, data, size);
 ptr += size;

 /* ETX */
 *ptr++ = ETX;

 /* send data */
 if (txSerial(buf, size + 3) == -1)
 {
  //free(buf); // Corrige erro memory leak (devemos nos certificar de que todos os pontos de retorno da função possuem uma chamada a free())
  return (-2); // Vazamento de memoria, erro no método txSerial, return sem liberar a memória.
 }

 /* free buffer */
 free(buf);

 return 0;
}

void main()
{
 char *msg = "MemoryLeak";

 if (!txData(msg))
  printf("Mensagem enviada com sucesso!\n");
 else
  printf("Erro ao enviar mensagem!\n");
}