// Solution-1:
#include <stdio.h>

int main() {
    int n, i, j, k;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter each element for the given array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Remove duplicates
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n;) {
            if (arr[j] == arr[i]) {
                // Shift all elements to the left
                for (k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
            } else {
                j++;
            }
        }
    }

    printf("Results: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Solution-2:
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int arr[], int start, int end) {
    if (start == end) {
        // Base case: we've generated a new permutation
        for (int i = 0; i <= end; i++) {
            printf("%d", arr[i]);
        }
        printf(" ");
    } else {
        // Recursive case: generate all permutations of the remaining elements
        for (int i = start; i <= end; i++) {
            // Swap the current element with the first element
            swap(&arr[start], &arr[i]);
            // Generate all permutations of the remaining elements
            permute(arr, start + 1, end);
            // Swap the current element back to its original position
            swap(&arr[start], &arr[i]);
        }
    }
}

int main() {
    int n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter each element for the given array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("All permutations: ");
    permute(arr, 0, n - 1);
    printf("\n");

    return 0;
}

// Solution-3:
#include <stdio.h>

int main() {
    int n, num = 1;
    printf("Enter the number of lines you want to print: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        // Print each line
        for (int j = 1; j <= i; j++) {
            printf("%d ", num++);
        }
        printf("\n");
    }

    return 0;
}

// Solution-4:
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int freq[26] = {0};

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("And second string: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2) {
        printf("No\n");
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        freq[str1[i] - 'a']++;
        freq[str2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");

    return 0;
}


// Solution-5:
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE], freq[MAX_SIZE];
    int size, i, j, count;

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter each element for the given array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1; // Initialize frequency array with -1
    }

    for (i = 0; i < size; i++) {
        count = 1;
        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = 0; // Set the frequency of duplicate elements to 0
            }
        }
        if (freq[i] != 0) {
            freq[i] = count;
        }
    }

    printf("\nFrequency for each element: \n");
    for (i = 0; i < size; i++) {
        if (freq[i] != 0) {
            printf("%d-%d\t", arr[i], freq[i]);
        }
    }

    return 0;
}
