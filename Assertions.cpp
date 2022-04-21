// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
//TEST_F(CollectionTest, AlwaysFail)
//{
//    FAIL();
//}

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    // if empty, the size must be 0
    if (collection->empty()) {
        add_entries(1);
        ASSERT_EQ(collection->size(), 1); 
        
    }
    //if collection is not empty
    if (collection->size()>0) {
        add_entries(1);
        ASSERT_EQ(2, collection->size()); 
    }
 }

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    if (collection->empty()) {
        add_entries(5);
        ASSERT_EQ(collection->size(), 5);

    }
    if (collection->size() > 0) {
        add_entries(5);
        ASSERT_EQ(10, collection->size());
    }
   // add_entries(5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, VerifyCollectionSize) {

    //when collection size is 0
    ASSERT_EQ(0, collection->size());
    ASSERT_TRUE(collection->max_size() >= collection->size());
    for (int i = 0; i < 1; ++i) {
        collection->push_back(i);

        //when collection size is 1
        ASSERT_EQ(1, collection->size());
        ASSERT_TRUE(collection->max_size() >= collection->size());
        collection->insert(collection->end(), 4, 10);

        //when collection size is 5
        ASSERT_EQ(5, collection->size());
        ASSERT_TRUE(collection->max_size() >= collection->size());
        collection->insert(collection->end(), 5, 10);

        //when collection size is 10
        ASSERT_EQ(10, collection->size());
        ASSERT_TRUE(collection->max_size() >= collection->size());
    }
}
// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, VerifyCollectionCapacity) {
    
    //when collection size is 0
    ASSERT_EQ(0, collection->size());
    ASSERT_TRUE(collection->capacity() >= collection->size());
    for (int i = 0; i < 1; ++i) {
        collection ->push_back(i);

        //when collection size is 1
        ASSERT_EQ(1, collection->size());
        ASSERT_TRUE(collection->capacity() >= collection->size());
        collection->insert(collection->end(), 4, 10);

        //when collection size is 5
        ASSERT_EQ(5, collection->size());
        ASSERT_TRUE(collection->capacity() >= collection->size());
        collection->insert(collection->end(), 5, 10);

        //when collection size is 10
        ASSERT_EQ(10, collection->size());
        ASSERT_TRUE(collection->capacity() >= collection->size());

    }
}
// TODO: Create a test to verify resizing increases the collection
TEST_F(CollectionTest, VerifyIncreaseCollection) {
    collection->resize(15);
    ASSERT_EQ(15, collection->size());
}

// TODO: Create a test to verify resizing decreases the collection
TEST_F(CollectionTest, VerifyDecreaseCollection) {
    collection->resize(5);
    ASSERT_EQ(5, collection->size());
}

// TODO: Create a test to verify resizing decreases the collection to zero
TEST_F(CollectionTest, VerifyResizeCollectionTo_0) {
    collection->resize(0);
    //assert equals ensures the collection size is 0
    //if the collection size is not 0, the test will fail
    ASSERT_EQ(0, collection->size());
}

// TODO: Create a test to verify clear erases the collection
TEST_F(CollectionTest, VerifyEraseCollection) {
    //clear() function clears and erases the collection
    collection->clear();
    ASSERT_TRUE(collection->empty());
    
   
}

// TODO: Create a test to verify erase(begin,end) erases the collection
TEST_F(CollectionTest, VerifyBeginEndErase) {
    collection->erase(collection->begin(), collection->end());

    //asserts true that collection is empty
    //if not empty, test will fail
    ASSERT_TRUE(collection->empty());
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
TEST_F(CollectionTest, VerifyReserveIncreasesCapacity) {
   //reserve() increases the capacity of the collection
    
    collection->reserve(25);
    for (int i = 0; i < 25; ++i) {
        collection->push_back(i);
        
    }
    //asserts that the capacity of collection is 25
    ASSERT_EQ(25, collection->capacity()); 
    
}

// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test
TEST_F(CollectionTest, VerifyRangeExceptionThrown) {
    for (unsigned i = 0; i < collection->size(); i++) {

        //out of range occurs when input is greater than or equal to collection size
        if (collection->at(i) >= collection->size()) {
            //test that the exception is thrown
            EXPECT_THROW({
                try {
                 collection->at(i);   //throws out of range exception
                 }
                 catch (const std::out_of_range& error) {
                     //expected handle
                 EXPECT_EQ(error.what(), std::string("Out of range"));
                 throw;
                 }
            }, std::out_of_range);
        }
        
      
    }
    

}

// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative


//Negative test - expected to throw logic error
TEST_F(CollectionTest, VerifyLogicException) {
    EXPECT_THROW({
        try {
        //throws logic error
        throw std::logic_error("Logic Error Occurred");
        }
        catch (const std::logic_error& error) {
            //expected handle
           EXPECT_EQ(error.what(), std::string("Logic Error Occurred"));

           throw;
        }
        }, std::logic_error);
}

//Positive test - vector::front
TEST_F(CollectionTest, VerifyFront) {
    collection->push_back(5);
    collection->push_back(2);
    collection->front() -= collection->back();
   
    //the test is expecting a value of 3. If the asserted value is incorrect or if the function is incorrect, the test will fail.
    //the assert statement tells the program that it is expecting the collection->front() to have a value of 3.
    ASSERT_EQ(3, collection->front()); 

    //ASSERT_EQ(2, collection->front());   // - causes test to fail as it asserts an inccorect value
}

