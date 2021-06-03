#include<string>
template<typename V>
class MapNode{
public:
	string key;
	V value;
	MapNode* next;

	MapNode(string key,V value){
		this->key = key;
		this->value = value;
		next = NULL;
	}

	~MapNode(){
		delete next;
	}
};


template<typename V>
class ourmap{
	MapNode<V>** buckets;
	int count;
	int numBuckets;

	int getBucketIndex(string key){
		int hashCode = 0;
		int currentcoeff = 1;

		for(int i = key.length()-1 ; i>=0 ; i--){
			hashCode+=key[i]*currentcoeff;
			hashCode = hashCode % numBuckets;
			currentcoeff*=37;
			currentcoeff = currentcoeff % numBuckets;
		}

		return hashCode%numBuckets;
	}


	void rehash(){
		MapNode<V>** temp = buckets;
		buckets = new MapNode<V>*[2*numBuckets];
		for(int i = 0 ; i<2*numBuckets ; i++){
			buckets[i] = NULL;
		}
		int oldBlucketCount = numBuckets;
		numBuckets*=2;
		count = 0;
		for(int i = 0; i<oldBlucketCount ; i++){
			MapNode<V>* head = temp[i];
			while(head!=NULL){
				string key = head->key;
				V value = head->value;
				insert(key,value);
				head = head->next;
			}
		}
		for(int i  = 0 ; i<oldBlucketCount ; i++){
			MapNode<V>* temp[i];
			delete head;
		}
		delete [] temp;

	}

public:
	double getLoadfactor(){
		return (1.0*count)/numBuckets;
	}

	ourmap(){
		count = 0;
		numBuckets = 5;
		buckets = new MapNode<V>*[numBuckets];
		for(int i = 0 ; i<numBuckets ; i++){
			buckets[i] = NULL;
		}
	}

	~ourmap(){
		for(int i = 0 ; i<numBuckets ; i++){
			delete numBuckets[i];
		}
		delete [] buckets;
	}

	int size(){
		return count;
	}

	V getValue(string key){
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		if(head!=NULL){
			if(head->key==key) return head->value;
			head = head->next;
		}
		return 0;
	}


public:
	void insert(string key , V value){
		int bucketIndex = getBucketIndex(key);
		MapNode<v>* head = buckets[bucketIndex];
		while(head!=NULL){
			if(head->key == key){
				head->value = value;
				return;
			}
			head = head->next;
		}
		head = numBuckets[bucketIndex];
		MapNode<V>* newNode = new MapNode<V>(key,value);
		newNode->next = head;
		numBuckets[bucketIndex] = newNode;
		count++;
		double loadFactor = (1.0*count)/numBuckets;
		if(loadFactor>0.7){
			rehash();
		}
	}

	V remove(string key){
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		MapNode<V>* prev = NULL;
		while(head!=NULL){
			if(head->key == key){
				if(prev!=NULL){
			    prev->next = head->next;
				}else{
					buckets[bucketIndex] = head->next;
				}
				head->next = NULL;
				V value = head->value;
				delete head;
				count--;
				return value;
			}

			head = head->next;

		}
		return 0;

	}


};