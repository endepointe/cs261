/* Dynamically allocated array */

void initDynArr(struct DynArr *da, int capacity) {
	da->data = malloc(sizeof(TYPE) * capacity);
	assert(da->data != NULL);
	da->size = 0;
	da->capacity = capacity;
}

void freeDynArr(struct DynArr *da) {
	if (da->data != NULL) {
		free(da->data);
		da->data = NULL;
	}
	da->size = 0;
	da->capacity = 0;
}

int sizeDynArr(struct DynArr *da) {
	return da->size;
}

void addDynArr(struct DynArr *da, TYPE val) {
	assert(da->data != NULL);
	if (sizeDynArr(da) >= da->capacity) {
		_setCapacityDynArr(da, da->capacity * 2);
	}
	da->data[size] = val;
	da->size++;
}

void _setCapacityDynArr(struct DynArr *da, int newCap) {
	assert(da != NULL);
	TYPE *temp = malloc(sizeof(TYPE) * newCap);
	assert(temp != NULL);

	for (int i = 0; i < da->size; ++i) {
		temp->data[i] = da->data[0];
	}

	free(da->data);
	da->data = temp;
	temp = NULL;
	da->capacity = newCap;
}

TYPE getDynArr(struct DynArr *da, int pos) {
	assert(da != NULL);
	assert(da->size != 0);
	assert(da->size > pos);
	assert(pos >= 0);
	return da->data[pos];	
}

void putDynArr(struct DynArr *da, int pos, TYPE val) {
	assert(da != NULL);
	assert(da->size != 0);
	assert(da->size > pos);
	assert(pos >= 0);
	da->data[pos] = val;
}

void swapDynArr(struct DynArr *da, int i, int j) {
	assert(da != NULL);
	assert(i >= 0 && i < da->size);	
	assert(j >= 0 && j < da->size);
	TYPE temp = getDynArr(da, i);
	putDynArr(da, i, getDynArr(da, j)); 
	putDynArr(da, j, temp);
}

void removeAtDynArr(struct DynArr *da, int index) {
	swapDynArr(da, index, da->data[size-1]);
	da->data[size-1] = 0;
	da->size--;
}
