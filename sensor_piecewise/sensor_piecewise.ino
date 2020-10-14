#define SNSR0 A0
#define SNSR1 A1
#define SNSR2 A2
#define SNSR3 A3
#define SNSR4 A4
#define SNSR5 A5
int sample = 30;

void setup() {
  Serial.begin(9600);

}

void loop() {
  
  Serial.print(sensorRead(sample, SNSR0));  Serial.print("\t");
  Serial.print(sensorRead(sample, SNSR1));  Serial.print("\t");
  Serial.print(sensorRead(sample, SNSR2));  Serial.print("\t");
  Serial.print(sensorRead(sample, SNSR3));  Serial.print("\t");
  Serial.print(sensorRead(sample, SNSR4));  Serial.print("\t");
  Serial.println(sensorRead(sample, SNSR5));
  // Serial.println(convertToCM(sensorRead(sample, SNSR))); //Uncomment only after function has been generated.

}

///// INSERT GENERATED convertToCM FUNCTION HERE ////////

/////////////////////////////////////////////////////////


double sensorRead(int n, int sensor){
  double x[n];
  int i;
//  int sum = 0;
  for(i=0;i<n;i++){
    delay(1);
    x[i] = analogRead(sensor);
  }
  mergeSort(x, n);
  return x[n/2];          //Return Median
}

void mergeSort(double ar[], int size){
    int i;
    if(size<2)
        return;
    else
    {
        int mid = size/2;
        double left[mid];
        double right[size-mid];
        for(i=0; i<mid; i++)
        {
            left[i] = ar[i];
        }
        for(i=mid; i<size; i++)
        {
            right[i-mid] = ar[i];
        }
        mergeSort(left, mid);
        mergeSort(right, size-mid);
        merge(ar, left, right, size);
    }
}

void merge(double ar[], double left[], double right[], int size){
    int i=0, j=0, k=0;
    int mid=size/2;
    while(i<mid && j<size-mid)
    {
        if(left[i]>right[j])
        {
            ar[k] = right[j];
            j++;
        }
        else
        {
            ar[k] = left[i];
            i++;
        }
        k++;
    }
    while(i<mid)
    {
        ar[k]=left[i];
        k++; i++;
    }
    while(j<size-mid)
    {
        ar[k]=right[j];
        j++; k++;
    }
}
