#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


typedef struct nghttp2_nv
{
	uint8_t *name;
   	uint8_t *value;
   	size_t namelen;
   	size_t valuelen;
   	uint8_t flags;

}nghttp2_nv;


int server_add_header_status(nghttp2_nv ***nv, int *num_nv, int count_nv, char **header_name, char **header_value)
{
	fprintf(stdout, "%s\n", "inside add header field");
	int temp = 0;
	nghttp2_nv **resp_nv = malloc(count_nv * sizeof(nghttp2_nv *));
	if (resp_nv == NULL)
	{
		fprintf(stdout, "failed to allocate memory at %s %d\n", __FILE__, __LINE__);
		return 0;
	}
	int i;
    for (i=0;i<count_nv; i++)
    {
    	resp_nv[i] = malloc(sizeof(nghttp2_nv));
    }     
	for(i=0;i<count_nv;i++)
	{
		
		resp_nv[i]->name = malloc(strlen(header_name[i]) + 1);
		if (resp_nv[i]->name == NULL)
		{
			fprintf(stdout, "failed to allocate memory at %s %d\n", __FILE__, __LINE__);
			return 0;
		}
		strcpy((char *)resp_nv[i]->name, header_name[i]);
		resp_nv[i]->namelen = strlen(header_name[i]);

		resp_nv[i]->value = malloc(strlen(header_value[i]) + 1);
		if (resp_nv[i]->value == NULL)
		{
			fprintf(stdout, "failed to allocate memory at %s %d\n", __FILE__, __LINE__);
			return 0;
		}
		strcpy((char *)resp_nv[i]->value, header_value[i]);
		resp_nv[i]->valuelen = strlen(header_value[i]);
		resp_nv[i]->flags = 0;
		temp++;
	}
	*nv = resp_nv;
	*num_nv = count_nv;

	return temp;
}

int main()
{
	nghttp2_nv **nv;
	int num_nv = 0;
	int count_nv = 2;
	int ret = 0;
	char *header_name[2] = {":status" , ":ProblemDetails"};
	char *header_value[2] = {"200", "3"};

	ret = server_add_header_status(&nv, &num_nv, count_nv, header_name, header_value);
	if(ret == 0)
	{
		fprintf(stderr, "failed to add header field at %s %d\n", __FILE__, __LINE__);

	}
	if(nv != NULL)
	{
		for(int i=0;i<count_nv;i++)
		{
			fprintf(stdout, "name -> %s\n", nv[i]->name);
			fprintf(stdout, "value -> %s\n", nv[i]->value);
			fprintf(stdout, "namelen -> %ld\n", nv[i]->namelen);
			fprintf(stdout, "valuelen -> %ld\n", nv[i]->valuelen);
			fprintf(stdout, "flags -> %d\n", nv[i]->flags);
		}
		
	}
	return 0;
}