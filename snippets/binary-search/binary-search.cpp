while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==key){
            ans=mid;
            break;
        }
        if(a[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }