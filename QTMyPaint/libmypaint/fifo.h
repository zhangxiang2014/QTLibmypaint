#ifndef FIFO_H
#define FIFO_H

typedef struct fifo Fifo;
typedef void (*FifoUserFreeFunction) (void *item_data);

Fifo* fifo_new(void);
void fifo_free(Fifo* self, FifoUserFreeFunction data_free);

void fifo_push(Fifo* self, void* data);
void* fifo_pop(Fifo* self);

void* fifo_peek_first(Fifo *queue);
void* fifo_peek_last(Fifo *queue);

#endif // FIFO_H
