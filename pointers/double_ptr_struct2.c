#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


#define FAILURE 0
#define SUCCESS 1

typedef struct nghttp2_nv
{
	uint8_t *name;
   	uint8_t *value;
   	size_t namelen;
   	size_t valuelen;
   	uint8_t flags;

}nghttp2_nv;


int server_add_header_status(nghttp2_nv **nv, int *num_nv, int count_nv, char *header_name, char *header_value)
{
	fprintf(stdout, "%s\n", "inside add header field");
	nghttp2_nv *resp_nv; 

	resp_nv = realloc(*nv, ((count_nv + 1) * sizeof(nghttp2_nv)));
	if (resp_nv == NULL)
	{
		fprintf(stdout, "failed to allocate memory at %s %d\n", __FILE__, __LINE__);
		return FAILURE;
	}

		
	resp_nv[count_nv].name = malloc(strlen(header_name) + 1);
	if (resp_nv[count_nv].name == NULL)
	{
		fprintf(stdout, "failed to allocate memory at %s %d\n", __FILE__, __LINE__);
		return FAILURE;
	}
	strcpy((char *)resp_nv[count_nv].name, header_name);
	resp_nv[count_nv].namelen = strlen(header_name);

	resp_nv[count_nv].value = malloc(strlen(header_value) + 1);
	if (resp_nv[count_nv].value == NULL)
	{
		fprintf(stdout, "failed to allocate memory at %s %d\n", __FILE__, __LINE__);
		return FAILURE;
	}
	strcpy((char *)resp_nv[count_nv].value, header_value);
	resp_nv[count_nv].valuelen = strlen(header_value);
	resp_nv[count_nv].flags = 0;

	*nv = resp_nv;
	*num_nv = count_nv;
	return SUCCESS;
}

int main()
{
	nghttp2_nv *nv = NULL;
	int num_nv = 0;
	int count_nv = 0;
	int ret = 0;

	ret = server_add_header_status(&nv, &num_nv, count_nv, ":method", "GET");
	if(ret == 0)
	{
		fprintf(stderr, "failed to add header field at %s %d\n", __FILE__, __LINE__);

	}

	count_nv = count_nv + ret;
	ret = server_add_header_status(&nv, &num_nv, count_nv, ":request_path", "/ue-authentication");
	if(ret == 0)
	{
		fprintf(stderr, "failed to add header field at %s %d\n", __FILE__, __LINE__);

	}
	count_nv = count_nv + ret;
	
	if(nv != NULL)
	{
		for(int i=0;i<count_nv;i++)
		{
			fprintf(stdout, "name -> %s\n", nv[i].name);
			fprintf(stdout, "value -> %s\n", nv[i].value);
			fprintf(stdout, "namelen -> %ld\n", nv[i].namelen);
			fprintf(stdout, "valuelen -> %ld\n", nv[i].valuelen);
			fprintf(stdout, "flags -> %d\n", nv[i].flags);
		}
		
	}
	return 0;
}