//
// Created by devesh on 9/8/19.
//


#include <bits/stdc++.h>

enum type {
    OBJ, ARR, STR, INT
};
struct data;
void printObject(const struct OBJ * ptr, int space=0);

struct OBJ {
    std::map<std::string, data *> obj;

    data *get(const std::string key) {
        return obj[key];
    }

    unsigned long size() {
        return obj.size();
    }

    void add(std::string key, struct data * d){
        obj[key] = d;
    }
};

struct ARR {
    std::vector<data *> arr;

    unsigned long size() {
        return arr.size();
    }

    void append(struct data * d){
        arr.push_back(d);
    }
};

struct data {
    type _type;
    void *ptr;

    data(const type t, void *p) {
        _type = t;
        ptr = p;
    }


    void *get() {

        switch (_type) {
            case INT:
                return (int *) ptr;

            case STR:
                return (std::string *) ptr;

            case OBJ:
                return (struct OBJ *) ptr;

            case ARR:
                return (struct ARR *) ptr;

            default:
                return new std::string("data type not supported");
        }
    }
};


void print(const data *d, int space = 0) {

    switch (d->_type) {
        case INT:
            std::cout << *((int *) d->ptr);
            break;

        case STR: {
            std::cout << '\"' << *((std::string *) d->ptr) << '\"';
        }   break;

        case ARR:
            {
                struct ARR *p = (struct ARR *) d->ptr;
                std::cout << "[";
                for (int i = 0; i < p->size(); i++) {
                    print(p->arr[i]);
                    if(i < p->size()-1)std::cout << ", ";
                }
                std::cout << "]";
        }   break;

        default: {
            struct OBJ *p = (struct OBJ *) d->ptr;
            printObject(p, space+4);
        }

    }
}

void printObject(const struct OBJ * ptr, int space) {

    std::cout << "{\n";
    auto i = ptr->obj.size();

    for(auto e: ptr->obj) { i--;
        for(int i=0; i < space + 4; i++)std::cout << " ";
        std::cout << e.first << ": ";
        print(e.second, space + 4);
        std::cout << ((i)? ", ": "") << '\n';
    }
    for(int i=0; i < space; i++)std::cout << " ";
    std::cout << "}";
}

int main(int args, char **argv) {

//    if(args > 1) {
//        std::cout << argv[1] << "\n";
//        std::ifstream json;
//
//        json.open(argv[1]);
//        if(!json) {
//            std::cout << "failed to ipen" << "\n";
//            return -1;
//        }
//
//        std::stack<> st;
//
//        int ascii = json.get();
//
//        while(ascii != EOF){
//            std::cout << char(ascii);
//            ascii = json.get();
//        }
//
//
//    } else {
//        std::cout << "NON" << "\n";
//    }


    auto *O = new struct OBJ();

    auto *O1 = new struct OBJ();

    int i = 10;
    int j = 20;
    std::string s = "Hello World";

    struct ARR *a = new struct ARR();

    a->append(new data(INT, &i));
    a->append(new data(INT, &j));
//    a->append(new data(OBJ, O1));
//    a->arr.push_back(new data(OBJ, O1));


    O->add("key1", new data(STR, &s));
    O->add("key2", new data(INT, &i));
    O->add("key3", new data(OBJ, O1));
//    O->add("key3", new data(ARR, a));

//    O->obj["key2"] = new data(INT, &i);
    O->obj["key4"] = new data(ARR, a);


    O1->obj["key1"] = new data(STR, &s);
    O1->obj["key2"] = new data(STR, &s);


//    print(O->get("key2"));
//    print(O->get("key3"));
    printObject(O, 0);

//    O->obj["key2"]->print();




    return 0;
}


