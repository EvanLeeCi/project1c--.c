        #include <stdio.h>
        #include <stdlib.h>
        #include <time.h>
        #include <math.h>

        // Function prototypes
        float findMin(float arr[], int size);
        float findMax(float arr[], int size);
        float calculateAverage(float arr[], int size);
        int findIndexOf(float arr[], int size, float num);
        int countOccurrences(float arr[], int size, float num);
        void printFirst100(float arr[]);
        float calculateMedian(float arr[], int size);
        float calculateMode(float arr[], int size);
        float calculateRange(float arr[], int size);
        float calculateVariance(float arr[], int size, float mean);
        float calculateStandardDeviation(float arr[], int size, float mean);
        void  sortArray(float arr[], int size);

        

        int main() {
            float balance[1000];
            int size = 1000;
            int choice = 0;

            // Initialize the array with random values between 0 and 100
            srand((unsigned int)time(NULL));
            for (int i = 0; i < size; i++) {
                balance[i] = ((float)rand() / RAND_MAX) * 100.0;
            }

            // Command line menu loop
            while (choice != 7) {
                printf("\nChoose an option:\n");
                printf("1. Find minimum\n");
                printf("2. Find maximum\n");
                printf("3. Calculate average\n");
                printf("4. Find index of a number\n");
                printf("5. Count occurrences\n");
                printf("6. Print first 100 elements\n");
                printf("7. Exit\n");
                printf("8. Calculate median\n");
                printf("9. Calculate mode\n");
                printf("10. Calculate range\n");
                printf("11. Calculate variance\n");
                printf("12. Calculate standard deviation\n");
                printf("13. Sort array\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 1) {
                    printf("The minimum is: %.2f\n", findMin(balance, size));
                } 
                else if (choice == 2) {
                    printf("The maximum is: %.2f\n", findMax(balance, size));
                } 
                else if (choice == 3) {
                    printf("The average is: %.2f\n", calculateAverage(balance, size));
                } 
                else if (choice == 4) {
                    float num;
                    printf("Enter the number to find its index: ");
                    scanf("%f", &num);
                    int index = findIndexOf(balance, size, num);
                    if (index == -1)
                        printf("The number %.2f was not found.\n", num);
                    else
                        printf("The index of %.2f is: %d\n", num, index);
                } 
                else if (choice == 5) {
                    float num;
                    printf("Enter the number to count its occurrences: ");
                    scanf("%f", &num);
                    int count = countOccurrences(balance, size, num);
                    printf("The number %.2f occurs %d times.\n", num, count);
                } 
                else if (choice == 6) {
                    printFirst100(balance);
                } 
                else if (choice == 7) {
                    printf("Exiting the program.\n");

//----------------- -------------------------part 2 -----------------------------------------------------
                
                } 
                else if (choice == 8) {
                    printf("The median is: %.2f\n", calculateMedian(balance, size));
                }
                else if(choice == 9){
                    printf("The mode is: %.2f\n", calculateMode(balance, size));
                }
                else if(choice == 10){
                    printf("The range is: %.2f\n", calculateRange(balance, size));
                }
                else if(choice == 11){
                    float mean = calculateAverage(balance, size);
                    printf("The variance is: %.2f\n", calculateVariance(balance, size, mean));
                }
                else if(choice == 12){
                    float mean = calculateAverage(balance, size);
                    printf("The standard deviation is: %.2f\n", calculateStandardDeviation(balance, size, mean));
                }
                else if(choice == 13){
                    sortArray(balance, size);
                    printf("The array has been sorted.\n");
                    
                }
                else {
                    printf("Invalid choice. Please try again.\n");
                }
            }

            return 0;
        }

        // ---------- Function Definitions part 1 ----------

        float findMin(float arr[], int size) {
            float min = arr[0];
            for (int i = 1; i < size; i++) {
                if (arr[i] < min) {
                    min = arr[i];
                }
            }
            return min;
        }

        float findMax(float arr[], int size){
            float max = arr[0];
            for (int i = 1; i < size; i++) {
                if (arr[i] > max) {
                    max = arr[i];
                }
            }
            return max;
        }

        float calculateAverage(float arr[], int size){
            float sum = 0.0;
            for (int i = 0; i < size; i++) {
                sum += arr[i];
            }
            return sum / size;
        }

        int findIndexOf(float arr[], int size, float num){
            for (int i = 0; i < size; i++) {
                if (arr[i] == num) {
                    return i;
                }
            }
            return -1;
        }

        int countOccurrences(float arr[], int size, float num){
            int count = 0;
            for (int i = 0; i < size; i++) {
                if (arr[i] == num) {
                    count++;
                }
            }
            return count;
        }

        void printFirst100(float arr[]){
            for (int i = 0; i < 100; i++) {
                printf("%.2f ", arr[i]);
            }
        }

        //----------------- part 2 Functions ----------------

        void sortArray(float arr[], int size){
            for (int i = 0; i < size - 1; i++){
                for (int j = 0; j < size - i - 1; j++){
                    if (arr[j] > arr[j + 1]){
                        float temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
                
        }

        float calculateMedian(float arr[], int size){
            if(size <= 0){
                return 0;
            }
            sortArray(arr, size);
            if(size % 2 == 1){
                return arr[size / 2];
            }

            return (arr[(size - 1) / 2] + arr[size / 2]) / 2.0;
        }

        float calculateMode(float arr[], int size){
            if(size <= 0){
                return 0;
            }
            sortArray(arr, size);
            float mode = arr[0];
            int maxCount = 1;
            int count = 1;

            for(int i = 1; i < size; i++){
                if((int)(arr[i] * 10.0f) == (int)(arr[i - 1] * 10.0f)){
                    count++;
                } else{
                    if(count > maxCount){
                        maxCount = count;
                        mode = arr[i - 1];
                    }
                    count = 1;
                }
            }
            if(count > maxCount){
                mode = arr[size - 1];
            }
            return mode;
                
        }

        float calculateRange(float arr[], int size){
            if(size <= 0){
                return 0;
            }
            float min = findMin(arr, size);
            float max = findMax(arr, size);
            return max - min;
        }

        
        float calculateVariance(float arr[], int size, float mean){
            if(size <= 0){
                return 0;
            }
            float sumsq = 0.0;
            for(int i = 0; i < size; i++){
                sumsq += (arr[i] - mean) * (arr[i] - mean);
                
            }
            return sumsq / size;
        }

        float calculateStandardDeviation(float arr[], int size, float mean){
            float variance = calculateVariance(arr, size, mean);
            return sqrtf(variance);
        }

        


