/**
    * File Name: 102_Binary_Tree_Level_Order_Traversal.c
    * Author: louis xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: Apr 4, 2016
*/

/**
	Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

	For example:
	Given binary tree {3,9,20,#,#,15,7},
		3
	   / \
	  9  20
		/  \
	   15   7
	return its level order traversal as:
	[
	  [3],
	  [9,20],
	  [15,7]
	]
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define QUEUE_INIT_SIZE 100
#define QUEUE_INC_SIZE 20

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct queue_s {
	struct TreeNode *elem;
	int queuesize;
	int front;
	int rear;
} queue_t;

queue_t * init_queue(void) {
	queue_t *q;
	q = (queue_t *) malloc(sizeof(queue_t));
	q->elem = (struct TreeNode *) malloc(sizeof(struct TreeNode) * QUEUE_INIT_SIZE);
	q->queuesize = QUEUE_INIT_SIZE;
	q->front = 0;
	q->rear = 0;
	return q;
}

int destroy_queue(queue_t *q) {
	if (!q) {
		return -1;
	}
	free(q->elem);
	q->elem = NULL;
	q->front = 0;
	q->rear = 0;
	q->queuesize =  0;
	free(q);
	q = NULL;
	return 0;
}

int empty_queue(queue_t *q) {
	return (q->front == q->rear);
}

int en_queue(queue_t *q, struct TreeNode T) {
	if (!q) {
		return -1;
	}
	if ((q->rear + 1) % q->queuesize == q->front) {
		q->elem = (struct TreeNode *) realloc(q->elem, (q->queuesize + QUEUE_INC_SIZE) * sizeof(struct TreeNode));
		q->queuesize += QUEUE_INC_SIZE;
	}
	q->elem[q->rear] = T;
	q->rear = (q->rear + 1) % q->queuesize;
	return 0;
}

int de_queue(queue_t *q, struct TreeNode *e) {
	if (!q || q->rear == q->front) {
		return -1;
	}
	*e = q->elem[q->front];
	q->front = (q->front + 1) % q->queuesize;
	return 0;
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
	int **solution;
	int total = 64, size = 0, i;
	queue_t *q;
	struct TreeNode e;

	solution = (int **) malloc(total * sizeof(int *));
	for (i = 0; i < total; i++) {
		solution[i] = (int *) malloc(sizeof(int));
	}
	columnSizes = (int **) malloc(total * sizeof(int *));
	for (i = 0; i < total; i++) {
		columnSizes[i] = (int *) malloc(sizeof(int));
	}

	q = init_queue();
	if (root) en_queue(q, root);
	while (!empty_queue(q)) {
		i = 0;
		de_queue(q, &e);
		if (e.left) en_queue(q, e.left);
		if (e.right) en_queue(q, e.right);
		solution[size][i++] = e.val;
	}

}
