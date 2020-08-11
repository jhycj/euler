#include <iostream>
#include<stdio.h>
struct node
{
	int block_depth;
	int block_depth_buf;
	int move_depth;
	int row;
	int col;
	char move;
	node *next;
	node *prev;
};

struct Mat
{
	node *data;
	int rows;
	int cols;
};

struct circular_queue
{
	node **data;
	int max_size;
	int size;
	int front;
	int rear;
};

void push(circular_queue *queue, node *node)
{
	if (queue->size == queue->max_size)
	{
		std::cout << "WARNING: queue is full" << std::endl;
		return;
	}
	queue->data[queue->rear++] = node;
	queue->size++;
	if (queue->rear == queue->max_size)
		queue->rear = 0;
}

node *pop(circular_queue *queue)
{
	node *ret = NULL;
	if (queue->size == 0)
	{
		std::cout << "WARNING: queue is empty" << std::endl;
		return NULL;
	}
	ret = queue->data[queue->front++];
	queue->size--;
	if (queue->front == queue->max_size)
	{
		queue->front = 0;
	}
	return ret;
}

void initialize_queue(circular_queue *q, int max_size)
{
	q->max_size = max_size;
	q->size = 0;
	q->front = 0;
	q->rear = 0;
	q->data = new node *[max_size];
}

void finalize_queue(circular_queue *q)
{
	delete q->data;
}
void initialize_Mat(Mat *mat, int rows, int cols)
{
	mat->data = new node[rows * cols];
	mat->rows = rows;
	mat->cols = cols;
}

void finalize_Mat(Mat *mat)
{
	delete mat->data;
}

node *get_node(Mat *mat, int row, int col)
{
	if (row >= 0 && row < mat->rows && col >= 0 && col < mat->cols)
		return &(mat->data[row * mat->cols + col]);
	else
		return NULL;
}

bool update_water(Mat *mat, int step)
{
	bool ret = false;
	for (int i = 0; i < mat->rows; ++i)
	{
		for (int j = 0; j < mat->cols; ++j)
		{
			node *cur_node = get_node(mat, i, j);
			node *near_node = NULL;
			int min_depth = 9999;

			if (cur_node->block_depth != -1)
			{
				continue;
			}
			if (near_node = get_node(mat, i - 1, j)) // this means near node in not nullptr
			{
				if (near_node->block_depth != -1 && near_node->block_depth < min_depth)
					min_depth = near_node->block_depth;
			}
			if (near_node = get_node(mat, i + 1, j)) // this means near node in not nullptr
			{
				if (near_node->block_depth != -1 && near_node->block_depth < min_depth)
					min_depth = near_node->block_depth;
			}
			if (near_node = get_node(mat, i, j - 1)) // this means near node in not nullptr
			{
				if (near_node->block_depth != -1 && near_node->block_depth < min_depth)
					min_depth = near_node->block_depth;
			}
			if (near_node = get_node(mat, i, j + 1)) // this means near node in not nullptr
			{
				if (near_node->block_depth != -1 && near_node->block_depth < min_depth)
					min_depth = near_node->block_depth;
			}
			if (min_depth != 9999)
			{
				cur_node->block_depth_buf = min_depth + step;
				ret = true;
			}
		}
	}
	for (int i = 0; i < mat->rows; ++i)
	{
		for (int j = 0; j < mat->cols; ++j)
		{
			node *cur_node = get_node(mat, i, j);
			cur_node->block_depth = cur_node->block_depth_buf;
		}
	}
	return ret;
}

int bfs(Mat *mat, node *start_node, node *goal_node)
{
	int step = 0;
	node *cur_node = start_node;
	node *near_node;
	int row, col;

	circular_queue q;
	initialize_queue(&q, 1000);
	push(&q, start_node);
	while (q.size != 0)
	{
		cur_node = pop(&q);
		step = cur_node->move_depth + 1;
		row = cur_node->row;
		col = cur_node->col;
		if (near_node = get_node(mat, row, col + 1))
		{
			if (near_node->block_depth > step && near_node->move_depth > step)
			{
				near_node->move = 'R';
				near_node->move_depth = step;
				near_node->prev = cur_node;
				push(&q, near_node);
			}
		}
		if (near_node = get_node(mat, row, col - 1))
		{
			if (near_node->block_depth > step && near_node->move_depth > step)
			{
				near_node->move = 'L';
				near_node->move_depth = step;
				near_node->prev = cur_node;
				push(&q, near_node);
			}
		}
		if (near_node = get_node(mat, row + 1, col))
		{
			// this is right move
			if (near_node->block_depth > step && near_node->move_depth > step)
			{
				near_node->move = 'D';
				near_node->move_depth = step;
				near_node->prev = cur_node;
				push(&q, near_node);
			}
		}
		if (near_node = get_node(mat, row - 1, col))
		{
			// this is left move
			if (near_node->block_depth > step && near_node->move_depth > step)
			{
				near_node->move = 'U';
				near_node->move_depth = step;
				near_node->prev = cur_node;
				push(&q, near_node);
			}
		}
	}
	finalize_queue(&q);
	return goal_node->move_depth;
}

int main()
{
	Mat mat; // this is matrix
	node *start_node, *goal_node;
	int n = 0;  // this is row size
	int m = 0;  // this is column size
	int a = 0;  // this is water propagation step
	int sx = 0; // this is your start position x
	int sy = 0; // this is your start position y
	int gx = 0; // this is your goal x
	int gy = 0; // this is your goal y
	char tmp_c;

	// get matrix size and initialize matrix.
	std::cin >> n >> m >> a;
	initialize_Mat(&mat, n, m);

	// fill matrix with proper values.
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			node *n = get_node(&mat, i, j);
			n->move = 'S'; // this is stop.
			n->row = i;
			n->col = j;
			n->move_depth = 9999;
			n->block_depth = -1;
			n->block_depth_buf = -1;
			std::cin >> tmp_c;
			if (tmp_c == 'F')
			{
				n->block_depth = 0;
				n->block_depth_buf = 0;
			}
			else if (tmp_c == 'Y')
			{
				n->move_depth = 0;
				sx = j;
				sy = i;
			}
			else if (tmp_c == 'S')
			{
				gx = j;
				gy = i;
			}
			else if (tmp_c == 'O')
			{
			}
		}
	}

	while (update_water(&mat, a))
	{
		// empty loop for making depth map
	}

	start_node = get_node(&mat, sy, sx);
	goal_node = get_node(&mat, gy, gx);
	int ans = bfs(&mat, start_node, goal_node);

	printf("%d\n", ans);

	node *iter = goal_node;
	while (iter != start_node)
	{
		iter->prev->next = iter;
		iter = iter->prev;
	}

	iter = start_node;
	while (iter != goal_node)
	{
		iter = iter->next;
		printf("%c\n", iter->move);
	}

	finalize_Mat(&mat);

	return 0;
}
// this is test input
// FOOOS
// OOOOO
// OOOOO
// YOOOO
// OOFFO