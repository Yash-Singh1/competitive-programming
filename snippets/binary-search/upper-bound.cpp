while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==key){
            low=mid+1;
        }
        else if(a[mid]<key){
            low=mid+1;
        }
        else if (a[mid] > key){
            high=mid-1;
            ans=mid;
        }
    }