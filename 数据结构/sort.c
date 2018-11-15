//¿ìËÙÅÅĞò
void QuicklySort(int *array, int begin, int end)
{
	int left = begin;
	int right = end;
	int temp = array[begin];
	while (left < right)
	{
		while (left < right && array[begin] < array[right])
		{
			right--;
		}
		if (left < right)
		{
			array[left++] = array[right];
		}

		while (left < right && array[begin] > array[right])
		{
			left++;
		}
		if (left < right)
		{
			array[right--] = array[left];
		}
		array[left] = temp;

		QuicklySort(array, begin, left - 1);
		QuicklySort(array, right + 1, end);
	}
}

//²åÈëÅÅĞò
void InsertSort(int *array, int size)
{
	if (size < 1)
		return;
	for (int i = 1; i < size; i++)
	{
		int temp = 0;
		if (array[i] < array[i - 1])
		{
			temp = array[i];
		}
		int j = 0;
		for (j = i - 1; j >= 0 && array[j] > temp; j--)
		{
			array[j + 1] = array[j];
		}
		array[j + 1] = temp;

	}
}

//Ï£¶ûÅÅĞò
void ShellSort(int *array, int size)
{
	for (int increment = (size << 1); increment > 0; increment /= 2)
	{
		for (int i = increment; i < size; i++)
		{
			int temp = array[i];
			int j = 0;
			for (j = i - increment; j >= 0 && array[j] > temp; j -= increment)
			{
				array[j + increment] = array[j];
			}
			array[j + increment] = temp;
		}
	}
}

//Ã°ÅİÅÅĞò
void BubbleSort(int *array, int size)
{
	for (int i = 0; i < size  - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] < array[j + 1])
			{
				int temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}
}

//Ñ¡ÔñÅÅĞò
void SelectSort(int *array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int k = i;
		int flag = 0;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] < array[k])
			{
				k = j;
				flag++;
			}
		}
		if (flag != 0)
		{
			int temp = array[i];
			array[i] = array[k];
			array[k] = temp;
		}
	}
}

//¹é²¢ÅÅĞò
void MergeSort(int *array, int left, int right)
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		MergeSort(array, left, mid);
		MergeSort(array, mid, right);
		MergeData(array, left, right, mid);
	}

}

void Adjust(int *array, int size, int parent)
{
	int child = (parent << 1) + 1;

	while (child < size)
	{
		if (((child + 1) < size) && array[child] < array[child + 1])
		{
			child += 1;
		}
		if (array[child] > array[parent])
		{
			Swap(array[child], array[parent]);
			parent = child;
			child = (parent << 1) + 1;
		}
		else
		{
			return;
		}
	}
}

void HeapSort(int *array, int size)
{
	int root = ((size - 2) >> 1);
	int end = size - 1;
	for (; root > 0; --root)
	{
		Adjust(array, size, root);
	}
	while (end > 0)
	{
		Swap(&array[0], array[end]);
		Adjust(array, end, 0);
	}
}


