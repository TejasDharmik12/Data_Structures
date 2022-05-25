#include <stdio.h>


void binarySearch(int[], int);
void insertionSort(int[], int);
void mergeSort(int[], int, int);

int main() {
	int size, arr[100],i,option,conti;
	do {
        printf("SEARCHING AND SORTING : \n");
        printf("1)Binary search\n");
        printf("2)Insertion sort\n");
        printf("3)Merge sort\n");
        printf("\nEnter the option: ");
		scanf("%d", &option);
		printf("Enter size of array: ");
		scanf("%d", &size);
		if (option == 1)
        {
            printf("Enter values of array in sorted way:\n");
            for(i = 0; i < size; i++)
            {
                scanf("%d", &arr[i]);
		    }
        }
		if (option ==2 || option == 3){
		printf("Enter values of array:\n");
		for(i = 0; i < size; i++) {
			scanf("%d", &arr[i]);
		}
		}
		switch(option) {
			case 1:
				binarySearch(arr, size);
				break;
			case 2:
				insertionSort(arr, size);
				break;
			case 3:
				mergeSort(arr, 0, size - 1);
				break;
			default:
				printf("Invalid option!");
		}

		if (option ==2 || option == 3){
        printf("The sorted array is:\n");
		for(i = 0; i < size; i++) {
			printf("%d ", arr[i]);
		}
		}

		printf("\n\nIf you want to continue press 1 ,for exit press 0:  ");
		scanf("%d", &conti);
	} while(conti == 1);

	return 0;
}

void binarySearch (int arr[], int size)
{
  int v,first,mid,last;
  printf("Enter value to find\n");
  scanf("%d", &v);

  first = 0;
  last = size - 1;
  mid = (first+last)/2;

  while (first <= last)
    {
    if (arr[mid] < v)
    {
        first = mid + 1;
    }
    else if (arr[mid] == v)
    {
        printf("%d found at location %d.\n", v, mid+1);
        break;
    }
    else
    {
      last = mid - 1;
    }
    mid = (first + last)/2;
  }
  if (first > last)
    printf("Element is not present\n");

}
void insertionSort(int arr[], int size)
{
int i,j,key;
   for(i=1;i<size;i++)
   {
      key=arr[i];
      j=i-1;
      while((j>=0)&&(arr[j]>key)){
         arr[j+1]=arr[j];
         j--;
      }
      arr[j+1]=key;
   }
      //for(i = 0; i < size; i++)
        //{
		//	printf("%d ", arr[i]);
		//}
}

void merge(int arr[], int mid, int low, int high)
{
    int i, j, k,b,n, arr2[20],size;
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            arr2[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            arr2[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        arr2[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        arr2[k] = arr[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = arr2[i];
    }


}

void mergeSort(int arr[], int low, int high)
{
    int mid,i,size;
    if(low<high)
    {
        mid = (low + high) /2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        merge(arr, mid, low, high);
    }

}


