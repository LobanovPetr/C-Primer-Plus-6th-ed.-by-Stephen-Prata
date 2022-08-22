// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <iterator>

struct Review {
    std::string title;
    int rating;
    double price;
};

void menu();
bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);
bool FillReview(Review & rr);
void ShowReview(const Review & rr);
int main()
{
    using namespace std;

    vector<shared_ptr<Review> > books;
    Review temp;
    while (FillReview(temp))
        books.push_back(shared_ptr<Review>(new Review(temp)));
    if (books.size() == 0)
    {
        cout << "No books\n";
        return 0;
    }
    
    vector<shared_ptr<Review> > alphabetic(books.begin(), books.end());
    vector<shared_ptr<Review> > price(books.begin(), books.end());
    vector<shared_ptr<Review> > rating(books.begin(), books.end());
    
    sort(alphabetic.begin(), alphabetic.end(), [](const shared_ptr<Review> a, const shared_ptr<Review>b){
        return a->title < b->title;
    });
    sort(price.begin(), price.end(), [](const shared_ptr<Review> a, const shared_ptr<Review> b){
        return a->price < b->price;
    });
    sort(rating.begin(), rating.end(), [](const shared_ptr<Review> a, const shared_ptr<Review> b){
        return a->rating < b->rating;
    });
    char ch;
    while (menu(), cin >> ch, ch != 'q')
    {
        switch (ch)
        {
            case 'i':
                for_each(books.begin(), books.end(), [](const shared_ptr<Review> b){ShowReview(*b);});
                break;
            case 'a':
                for_each(alphabetic.begin(), alphabetic.end(), [](const shared_ptr<Review> b){ShowReview(*b);});
                break;
            case 'r':
                for_each(rating.begin(), rating.end(), [](const shared_ptr<Review> b){ShowReview(*b);});
                break;
            case 'p':
                for_each(price.begin(), price.end(), [](const shared_ptr<Review> b){ShowReview(*b);});
                break;
            case 'P':
                for_each(price.rbegin(), price.rend(), [](const shared_ptr<Review> b){ShowReview(*b);});
                break;
        }
    }
    
    cout << "Bye.\n";
    return 0;
}

void menu()
{
    using namespace std;
    cout << "Coose a variant:\n";
    cout << "i - initial order\t" << "a - alphabetic order\n";
    cout << "r - raiting increasing\t" << "p - price increasing\n";
    cout << "P - price decreasing\t" << "q - to stop\n";
}

bool operator<(const Review & r1, const Review & r2)
{
    if (r1.title < r2.title)
        return true;
    else if (r1.title == r2.title && r1.rating < r2.rating)
        return true;
    else
        return false;
}

bool worseThan(const Review & r1, const Review & r2)
{
    if (r1.rating < r2.rating)
        return true;
    else
        return false;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin,rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
    {
        std::cin.clear();
        while(std::cin.get() != '\n');
        return false;
    }
    while (std::cin.get() != '\n');
    std::cout << "Enter book price: ";
    std::cin >> rr.price;
    if (!std::cin)
    {
        std::cin.clear();
        while(std::cin.get() != '\n');
        return false;
    }
    while (std::cin.get() != '\n');
    return true;
}

void ShowReview(const Review & rr)
{
    std::cout << rr.price << "\t" << rr.rating << "\t" << rr.title << std::endl;
}
