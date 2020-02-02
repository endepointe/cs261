/* Dynamically allocated array */

#ifndef DYNARRAY_H
#define DYNARRAY_H
#ifndef TYPE
#define TYPE int
#endif

struct DynArr {
	TYPE *data;
	int size;
	int capacity;
};

void initDynArr(struct DynArr *da, int capacity);

void freeDynArr(struct DynArr *da);

int sizeDynArr(struct DynArr *da);

void addDynArr(struct DynArr *da, TYPE val);

void _setCapacityDynArr(struct DynArr *da, int newCap);

TYPE getDynArr(struct DynArr *da, int pos);

void putDynArr(struct DynArr *da, int pos, TYPE val);

void swapDynArr(struct DynArr *da, int i, int j);

void removeAtDynArr(struct DynArr *da, int index);
#endif

