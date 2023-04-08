#include <stdlib.h>

void insSort(int size, int *array) {
    int temp, location;
    for (int i = 0; i < size; i++)
    {
        temp = array[i];
        location = i - 1;
        while (location >= 0 && array[location] > temp)
        {
            array[location + 1] = array[location];
            location = location - 1;
        }
        array[location + 1] = temp;
    }
}

void insSortGuard_I (int size, int *array) {
    int min_ind = 0;

    for (int i = 1; i < size; i++) {
        if (array[i] < array[min_ind]) min_ind = i;
    }

    int temp = array[min_ind];
    array[min_ind] = array[0];
    array[0] = temp;

    for (int i = 2; i < size; i++) {
        int value = array[i];
        int j;

        for (j = i - 1; array[j] <= value; j--) {
            array[j + 1] = array[j];
        }

        array[j + 1] = value;
    }
}

void insSortGuard_II (int size, int *array) { 
	int *temp_array, N;
	
	N = size + 1;
	
	temp_array = (int*)malloc(N*sizeof(int));
	temp_array[0] = 0;
	
	for (int i = 1; i < N; i++) {
		temp_array[i] = array[i - 1];
	}
	
	for (int i = 2; i < N; i++) {
    	temp_array[0] = temp_array[i];
    	for (int j = i - 1; temp_array[j] > temp_array[0]; j--) {
        	temp_array[j + 1] = temp_array[j];
        	temp_array[j] = temp_array[0];
    	}
	}
		
	for (int i = 0; i < size; i++) {
		array[i] = temp_array[i + 1];
	}
	
	free (temp_array);
}

void insSort_Sh (int size, int *array, int step) {

    int temp, location;
    for (int i = step; i < size; i++)
    {
        temp = array[i];
        location = i - step;
        while(location >= 0 && array[location] > temp)
        {
            array[location + step] = array[location];
            location = location - step;
        }
        array[location + step] = temp;
    }
}

void ShellSort (int size, int *array) {
	int d = size;
	int step = 0;
	if (size >= 500) {
		step = (d - 1) / 2;
		if (step < 1) step = 1;
		while (step >= 1) {
            insSort_Sh(size, array, step);
			d = step;
			step = (d - 1) / 2;
			if (step < 1 && d != 1) step = 1;
		}
	}
	else {
		step = (d - 1) / 3;
		if (step < 1) step = 1;
		while (step >= 1) {
			insSort_Sh(size, array, step);
			d = step;
			step = (d - 1) / 3;
			if (step < 1 && d != 1) step = 1;
		}
	}
}

void selSort(int size, int *array) {
    for (int i = size; i > 1; i--) {
        int max_ind = 0;

        for (int j = 1; j < i; j++) {
            if (array[max_ind] < array[j]) max_ind = j;
        }

        int temp = array[max_ind];
        array[max_ind] = array[i - 1];
        array[i - 1] = temp;
    }
}

void bubbleSort(int size, int *array) {
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (array[j] < array[j - 1]) {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}

void combSort(int size, int *array) {
    int step = size - 1;

    while (step > 0) {
        int flag = 1;

        while (flag == 1) {
            flag = 0;

            int i, j;
            for (i = 0, j = step; j < size; i++, j++) {
                if (array[i] > array[j]) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;

                    flag = 1;
                }
            }
        }

        step = (step * 8) / 11;
    }
}

void quickSort (int size, int *array) {
    int i = 0;
    int j = size - 1;

    int mid = array[size / 2];
    do {
        while(array[i] < mid) {
            i++;
        }
        while(array[j] > mid) {
            j--;
        }
        if (i <= j) {
            int temp;                    
	        temp = array[i];                  
	        array[i] = array[j];
	        array[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if(j > 0) {
        quickSort(j + 1, array);
    }
    if (i < size) {
        quickSort(size - i, &array[i]);
    }
}