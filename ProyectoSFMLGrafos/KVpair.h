#ifndef KVPAIR_H
#define KVPAIR_H

template <typename K, typename V>
class KVpair{
private:
    K key;
    V value;

public:
    KVpair(){}
    KVpair(K key){
        this->key=key;
    }
    KVpair(K key, V value){
        this->key=key;
        this->value=value;
    }
    K getKey(){
        return key;
    }
    void setKey(K key){
        this->key=key;
    }
    V getValue(){
        return value;
    }
    void setValue(V value){
        this->value=value;
    }
    void operator=(const KVpair &obj){
        this->key= obj.key;
        this->value=obj.value;
    }
    bool operator==(const KVpair &obj){
        return this->key==obj.key;
    }
    bool operator != (const KVpair &obj){
        return this->key != obj.key;
    }
    bool operator<(const KVpair &obj){
        return this->key<obj.key;
    }
    bool operator>(const KVpair &obj){
        return this->key>obj.key;
    }
    bool operator<=(const KVpair &obj){
        return this->key<=obj.key;
    }
    bool operator>=(const KVpair &obj){
        return this->key>=obj.key;
    }
};

#endif // KVPAIR_H
