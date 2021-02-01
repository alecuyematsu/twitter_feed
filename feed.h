#pragma once

#include "post.h"

/* Here is an example of defining a `point` struct with a typedef 
 * delete it in your final code, this is just an example
 */
// typedef struct point {
//     double x;
//     double y;
// } point;

/* Define feed type below */
typedef struct feed {
	int num_posts;
	int max_posts;
	post* posts;
} feed;


/* function prototypes; should be implemented in feed.c */

/// Creates a new feed object on the heap
feed* create_feed(int max_p);

/// Adds a post to the feed.
/// Returns 0 on success, -1 if f or p is NULL, and -2 if no more 
/// room.
int add_post(feed* f, post* p);

/// Deletes the i'th post from f.
/// Returns 0 on success, -1 if f is NULL, and -2 if no such index
int delete_post(feed* f, int i);

/// Prints the feed to stdout
void print_feed(feed* f);

/// Frees the memory for a particular feed object
void free_feed(feed* f);