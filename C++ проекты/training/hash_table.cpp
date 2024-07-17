#include <iostream>
#include <cstring>

constexpr int CAPACITY { 50000 };

unsigned long hash_function(char* str)
{
    unsigned long i {};

    for (int j{}; str[j]; ++j)
        i += str[j];

    return i % CAPACITY;
}

struct Ht_item
{
    char* key;
    char* value;
};

struct LinkedList
{
    Ht_item* item;
    LinkedList* next;
};

struct HashTable
{
    Ht_item** items;
    LinkedList** overflow_buckets;
    int size{};
    int count{};
};

Ht_item* create_item(char* key, char* value)
{
    Ht_item* item { (Ht_item*) malloc(sizeof(Ht_item)) };
    item->key = (char*) malloc(strlen(key) + 1);
    item->value = (char*) malloc(strlen(value) + 1);
    strcpy(item->key, key);
    strcpy(item->value, value);
    return item;
}

LinkedList** create_overflow_buckets(HashTable* table)
{
    LinkedList** buckets { (LinkedList**) calloc(table->size, sizeof(LinkedList*)) };

    for (int i{ 0 }; i < table->size; ++i)
    {
        buckets[i] = nullptr;
    }

    return buckets;
}

HashTable* create_table(int size)
{
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item**) calloc(table->size, sizeof(Ht_item*));

    for (int i{}; i < table->size; ++i)
        table->items[i] = nullptr;

    table->overflow_buckets = create_overflow_buckets(table);

    return table;
}

void free_item(Ht_item* item)
{
    free(item->key);
    free(item->value);
    free(item);
}

void free_table(HashTable* table)
{
    for (int i {}; i < table->size; ++i)
    {
        Ht_item* item = table->items[i];

        if (item != nullptr)
            free_item(item);
    }

    free(table->overflow_buckets);
    free(table->items);
    free(table);
}

void print_table(HashTable* table)
{
    std::cout << "\nHash Table\n---------------------\n";

    for (int i{}; i < table->size; ++i)
    {
        if (table->items[i])
        {
            std::cout << "Index: " << i << ", Key: " << table->items[i]->key << ", Value: " << table->items[i]->value << '\n';
        }
    }

    std::cout << "-------------------------\n\n";
}

LinkedList* allocate_list()
{
    LinkedList* list { (LinkedList*) malloc(sizeof(LinkedList)) };
    return list;
}

LinkedList* linkedlist_insert(LinkedList* list, Ht_item* item)
{
    if (!list)
    {
        LinkedList* head { allocate_list() };
        head->item = item;
        head->next = nullptr;
        list = head;
        return list;
    }
    else if (list->next == nullptr)
    {
        LinkedList* node { allocate_list() };
        node->item = item;
        node->next = nullptr;
        list->next = node;
        return list;
    }

    LinkedList* temp { list };

    while (temp->next->next)
    {
        temp = temp->next;
    }

    LinkedList* node { allocate_list() };
    node->item = item;
    node->next = nullptr;
    temp->next = node;
    return list;
}

void handle_collision(HashTable* table, unsigned long index, Ht_item* item)
{
    LinkedList* head { table->overflow_buckets[index] };

    if(head == nullptr)
    {
        head = allocate_list();
        head->item = item;
        table->overflow_buckets[index] = head;  
        return;
    }
    table->overflow_buckets[index] = linkedlist_insert(head, item);
    return;
}

void ht_insert(HashTable* table, char* key, char* value)
{
    Ht_item* item { create_item(key, value) };
    int index { static_cast<int>(hash_function(key)) };

    Ht_item* current_item { table->items[index] };

    if (current_item == nullptr)
    {
        if (table->count == table->size)
        {
            std::cout << "Insert Error: Hash Table is full\n";
            free_item(item);
            return;
        }

        table->items[index] = item;
        table->count++;
    }
    else 
    {
        if (strcmp(current_item->key, key) == 0)
        {
            strcpy(table->items[index]->value, value);
            return;
        }
        else
        {
            handle_collision(table, index, item);
            return;
        }
    }
}

char* ht_search(HashTable* table, char* key)
{
    int index { static_cast<int>(hash_function(key)) };
    Ht_item* item { table->items[index] };
    LinkedList* head { table->overflow_buckets[index] };

    if (item != nullptr)
    {
        if (strcmp(item->key, key) == 0)
        {
            return item->value;
        }

        if (head == nullptr)
        {
            return nullptr;
        }

        item = head->item;
        head = head->next;
    }

    return nullptr;
}

void print_search(HashTable* table, char* key)
{
    char* val{ ht_search(table, key) };

    if (val == nullptr)
    {
        std::cout << "Key " << key << " does not exist\n";
        return;
    }
    else 
    {
        std::cout << "Key: " << key << ", Value: " << val << '\n';
    }
}

Ht_item* linkedlist_remove(LinkedList* list)
{
    if (!list)
        return nullptr;

    if (!list->next)
        return nullptr;

    LinkedList* node { list->next };
    LinkedList* temp { list };
    temp->next = nullptr;
    list = node;
    Ht_item* it { nullptr };
    memcpy(temp->item, it, sizeof(Ht_item));
    free(temp->item->key);
    free(temp->item->value);
    free(temp->item);
    free(temp);
    return it;
}

void free_linkedlist(LinkedList* list)
{
    LinkedList* temp { list };

    while (list)
    {
        temp = list;
        list = list->next;
        free(temp->item->key);
        free(temp->item->value);
        free(temp->item);
        free(temp);
    }
}

void free_overflow_buckets(HashTable* table)
{
    LinkedList** buckets { table->overflow_buckets };

    for (int i{ 0 }; i < table->size; ++i)
    {
        free_linkedlist(buckets[i]);
    }

    free(buckets);
}

void ht_delete(HashTable* table, char* key)
{
    int index { static_cast<int>(hash_function(key)) };
    Ht_item* item { table->items[index] };
    LinkedList* head { table->overflow_buckets[index] };

    if (item == nullptr)
    {
        return;
    }
    else 
    {
        if (head == nullptr && strcmp(item->key, key) == 0)
        {
            table->items[index] = nullptr;
            free_item(item);
            table->count--;
            return;
        }
        else if (head != nullptr)
        {
            if (strcmp(item->key, key) == 0)
            {
                free_item(item);
                LinkedList* node { head };
                head = head->next;
                node->next = nullptr;
                table->items[index] = create_item(node->item->key, node->item->value);
                free_linkedlist(node);
                table->overflow_buckets[index] = head;
                return;
            }

            LinkedList* curr { head };
            LinkedList* prev { nullptr };

            while(curr)
            {
                if (strcmp(curr->item->key, key) == 0)
                {
                    if (prev == 0)
                    {
                        free_linkedlist(head);
                        table->overflow_buckets = nullptr;
                        return;
                    }
                    else
                    {
                        prev->next = curr->next;
                        curr->next = nullptr;
                        free_linkedlist(curr);
                        table->overflow_buckets[index] = head;
                        return;
                    }
                }

                curr = curr->next;
                prev = curr;
            }
        }
    }
}

int main()
{
    HashTable *ht = create_table(CAPACITY);
    ht_insert(ht, (char *)"1", (char *)"First address");
    ht_insert(ht, (char *)"2", (char *)"Second address");
    ht_insert(ht, (char *)"Hel", (char *)"Third address");
    ht_insert(ht, (char *)"Cau", (char *)"Fourth address");
    print_search(ht, (char *)"1");
    print_search(ht, (char *)"2");
    print_search(ht, (char *)"3");
    print_search(ht, (char *)"Hel");
    print_search(ht, (char *)"Cau"); // Collision!
    print_table(ht);
    ht_delete(ht, (char *)"1");
    ht_delete(ht, (char *)"Cau");
    print_table(ht);
    free_table(ht);
    return 0;
}