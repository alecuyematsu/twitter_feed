//Alec Uyematsu post.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "post.h"

/// creates a new post with the given fields;
/// will truncate author and contents if necessary
post create_post(char* author, int likes, char* contents) {

	post* my_post = malloc(sizeof(post)); //allocates memory on the heap
	strncpy(my_post->author, author, MAX_NAME_LENGTH); //strncpy coppies the string 
	strncpy(my_post->contents, contents, MAX_POST_LENGTH);
	my_post->likes = likes; //copies the likes
	return *my_post;
}

/// true if post is "viral" (twice as many likes as length), 
/// false otherwise.
int post_is_viral(post* p){
	int length = 2*strlen(p->contents);
	if (p->likes > length)//if p is viral return 1 else return 2
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

/// prints a post to stdout
void print_post(post* p) {

	printf("**%s**\n %s\n %i <3\n", p->author, p->contents, p->likes);
	
}
