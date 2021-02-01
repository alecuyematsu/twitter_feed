//Alec Uyematsu feed.c

#include <stdio.h>
#include <stdlib.h>
#include "feed.h"
#include "post.h"
#include <string.h>

feed* create_feed(int max_p) {
	feed *ptrFeed = (feed*) malloc(sizeof(feed)); //Allocates memory on the heap for the size of feed
		ptrFeed->num_posts = 0; //sets num_posts equal to zero
	if (max_p > 10) //if max posts is greater then 10 then max posts equals max posts
	{
		ptrFeed->max_posts = max_p; 
	}
	else //else max posts equals ten
	{
		ptrFeed->max_posts = 10;
	}
	post* posts = (post*) malloc(max_p * sizeof(post)); //allocating memory on the heap
	ptrFeed->posts = posts; 

	return ptrFeed;
}

/// Adds a post to the feed.
/// Returns 0 on success, -1 if f or p is NULL, and -2 if no more 
/// room.
int add_post(feed* f, post* p){
	if (f == NULL || p == NULL) { //if f or p is null return -1
		return -1; 
		
	}
	if (f->num_posts >= f->max_posts) { //if the number of posts is greater then max posts return -2
		return -2; 
		
	}

strcpy(f->posts[f->num_posts].author, p->author); //copies author
strcpy(f->posts[f->num_posts].contents, p->contents); //copies contents
f->posts[f->num_posts].likes = p->likes; //copies likes
f->num_posts = f->num_posts+1; //adds one to num posts
}

/// Deletes the i'th post from f.
/// Returns 0 on success, -1 if f is NULL, and -2 if no such index
int delete_post(feed* f, int i) {

if (f == NULL) //if f is null return -1
{
	return -1;
}

if (f->num_posts < i || i < 0) //if num posts is less then i or i is less then 0 return -2
{
	return -2;
} 

while (i < f->num_posts) //while i is less than num posts
{
	
		post postI = f->posts[i]; //creates new postI
		post nextPost = f->posts[i+1]; //creates nexPost
		
		postI.likes = nextPost.likes; //sets the postI likes equal to postNext likes
		strcpy(postI.contents, nextPost.contents); //strcpy is used for copying
		strcpy(postI.author, nextPost.author);
		i++;
}
		f->num_posts = (f->num_posts - 1); //num posts -1
return 0;
}

/// Prints the feed to stdout
void print_feed(feed* f) {
	
int number = f->num_posts;

printf("## Viral Posts ##\n");
 	for (int i = 0; i < number; i++)  //for loop that goes through posts
	 {
 		post newPost = f->posts[i]; //creates newPost 
 		if (post_is_viral(&newPost)) //if it is viral
		{
 			print_post(&newPost); //print viral posts
 				for(int i = 0; i < 51; i++) //for loop that prints 50 -
				{
					printf("-");
				}
			printf("\n");
 		}
 		
 	
	else
	{
 	printf("## Other Posts##\n"); //same as last section except with non viral posts
 		 		
 		post newPost2 = f->posts[i];
 			print_post(&newPost2);
 			for(int i = 0; i < 51; i++) 
				{
					printf("-");
				}
 			printf("\n");
	}
}
}

/// Frees the memory for a particular feed object
void free_feed(feed* f) {
	free(f->posts);
	free(f);
}
