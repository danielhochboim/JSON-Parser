#include "read_file.h"

int read_file(const char* file_name)
{
	FILE* fp;
	int file_size = 0;
	int read_bytes = 0;
	char* buff;
	//char buff[16];

	if (!file_name)
	{
		return -1;
	}

	fopen_s(&fp,file_name, "r");

	if (fp == NULL) {
		printf("Error: File Not Found\n");
		return -1;
	}

	file_size = get_file_size(fp);

	if (file_size == -1) {
		return -1;
	}
	if (file_size < 0)
	{
		return -1;
	}
	buff = (char*)malloc(file_size * sizeof(char) + 1);

	if (fgets(buff, file_size + 1, fp) == NULL){
		printf("error");
	}

	//if (fscanf(fp, 200, fp) == NULL) {
	//	printf("errorrrrrrrr");
	//}

	printf("%s", buff);

	/*
	*out_file_data = (char*)malloc(file_size * sizeof(char) + 1);
	if (!*out_file_data)
	{
		err = ERR_MALLOC_FAILED;
		goto fail;
	}

	read_bytes = (int)read(fd, *out_file_data, file_size);
	if (read_bytes != file_size)
	{
		printf("Failed reading %d bytes from %s\n", file_size, filename);
		err = ERR_BAD_FILE;
		goto fail;
	}

	(*out_file_data)[read_bytes] = 0;
	err = ERR_SUCCESS;

fail:
	if (fd != -1)
	{
		close(fd);
	}
	return err;*/
	return 0;
}

int get_file_size(FILE* fp)
{
	if (fp == NULL) {
		return -1;
	}
	fseek(fp, 0L, SEEK_END);
	long int res = ftell(fp);
	return res;
}