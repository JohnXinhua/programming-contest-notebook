#define LOGMAX ??

int tree[(1<<LOGMAX)+1];
int MaxVal = (1<<LOGMAX);

// O(log MaxVal)
int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

// O(log MaxVal)
void update(int idx ,int val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

// c * O(log MaxVal), where c is less than 1
int read_single(int idx){
    int sum = tree[idx]; // sum will be decreased
    if (idx > 0){ // special case
        int z = idx - (idx & -idx); // make z first
        idx--; // idx is no important any more, so instead y, you can use idx
        while (idx != z){ // at some iteration idx (y) will become z
            sum -= tree[idx];
    // substruct tree frequency which is between y and "the same path"
            idx -= (idx & -idx);
        }
    }
    return sum;
}

// O(MaxVal)
void scale(int c){
    for (int i = 1 ; i <= MaxVal ; i++)
        tree[i] = tree[i] / c;
}

// return the greatest index with given cumulative frequency
// O(log MaxVal)
int find_gidx(int cumFre){
    int idx = 0;

    while ((bitMask != 0) && (idx < MaxVal)){
        int tIdx = idx + bitMask;
        if (cumFre >= tree[tIdx]){
                // if current cumulative frequency is equal to cumFre,
                // we are still looking for higher index (if exists)
            idx = tIdx;
            cumFre -= tree[tIdx];
        }
        bitMask >>= 1;
    }
    if (cumFre != 0)
        return -1;
    else
        return idx;
}