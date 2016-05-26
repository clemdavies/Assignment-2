#include "TestBinarySearchTree.h"

stringstream TestBinarySearchTree::printString;

TestBinarySearchTree::TestBinarySearchTree(TestingTools &initTools)
{
  tools = &initTools;
  tools->setClassName("BinarySearchTree");
}

TestBinarySearchTree::~TestBinarySearchTree()
{
  //dtor
}

void TestBinarySearchTree::all()
{
  construction();
  insertNodes();
  removeNodes();
  processNodes();
  search();
}

void TestBinarySearchTree::construction()
{
  tools->setFunctionName("construction");
  {
    BinarySearchTree<int> instance1;
    BinarySearchTree<int> instance2;

    tools->assertTypeEquals(instance1,instance2);
  }
}

void TestBinarySearchTree::insertNodes()
{
  tools->setFunctionName("insertNodes");
  {
    BinarySearchTree<int> instance;

    tools->description("Insert root");
    instance.insert(5);
    tools->assertFalse(instance.isEmpty());

    instance.insert(10);
    tools->assertTrue(instance.search(10));

    tools->description("Insert root->lnode");
    instance.insert(3);
    tools->assertTrue(instance.search(3));

    tools->description("Insert root->lnode->lnode");
    instance.insert(2);
    tools->assertTrue(instance.search(2));

    tools->description("Insert root->rnode->rnode");
    instance.insert(12);
    tools->assertTrue(instance.search(12));

  }
  {
    BinarySearchTree<Date> instance;
    Date date1(19,5,2016);
    Date date2(20,5,2016);
    Date date3(19,6,2016);
    Date date4(21,5,2015);
    Date date5(19,6,2015);

    instance.insert( date1 );
    instance.insert( date2 );
    instance.insert( date3 );
    instance.insert( date4 );
    instance.insert( date5 );

    vfp<Date> print = TestBinarySearchTree::nodePrint;


    tools->description("DATE:");

    stringstream sstream;
    tools->description("InOrder:");
    clearSStreams(sstream);
    instance.inOrder( print );
    sstream << date4 << "," << date5 << "," << date1 << "," << date2 << "," << date3 << ",";
    tools->assertEquals( printString.str() ,sstream.str());

    tools->description("PreOrder:");
    clearSStreams(sstream);
    instance.preOrder( print );
    sstream << date1 << "," << date4 << "," << date5 << "," << date2 << "," << date3 << ",";
    tools->assertEquals( printString.str() ,sstream.str());

    tools->description("PostOrder:");
    clearSStreams(sstream);
    instance.postOrder( print );
    sstream << date5 << "," << date4 << "," << date3 << "," << date2 << "," << date1 << ",";
    tools->assertEquals( printString.str() ,sstream.str());

  }
}

void TestBinarySearchTree::removeNodes()
{
  tools->setFunctionName("removeNodes");
  {
    BinarySearchTree<int> instance;
    instance.insert(5);
    instance.insert(10);
    instance.insert(3);
    instance.insert(2);
    instance.insert(12);
    instance.insert(6);
    instance.insert(8);
    instance.insert(1);

    tools->description("inserted 5,10,3,2,12,6,8,1");
    tools->description("           5");
    tools->description("     3          10");
    tools->description("  2     -      6  12");
    tools->description(" 1 -          - 8");



    tools->description("remove non existent node (110)");
    tools->assertFalse(instance.search(110));
    instance.remove(110);
    tools->assertFalse(instance.search(110));
    tools->description("remove non existent node (0)");
    tools->assertFalse(instance.search(0));
    instance.remove(0);
    tools->assertFalse(instance.search(0));

    tools->description("remove node (8)");
    tools->assertTrue(instance.search(8));
    instance.remove(8);
    tools->assertFalse(instance.search(8));

    tools->description("reinsert node (8)");
    instance.insert(8);
    tools->assertTrue(instance.search(8));

    tools->description("remove node (6)");
    tools->assertTrue(instance.search(6));
    instance.remove(6);
    tools->assertFalse(instance.search(6));

    tools->description("           5");
    tools->description("     3          10");
    tools->description("  2     -      8  12");
    tools->description(" 1 -");

    tools->description("remove root node (5)");
    tools->assertTrue(instance.search(5));
    instance.remove(5);
    tools->assertFalse(instance.search(5));

    tools->description("           10");
    tools->description("     8          12");
    tools->description("  3     -      -  -");
    tools->description(" 2 -");
    tools->description("1 -");

    tools->description("remove root node (10)");
    tools->assertTrue(instance.search(10));
    instance.remove(10);
    tools->assertFalse(instance.search(10));


    tools->description("remove root node (12)");
    tools->assertTrue(instance.search(12));
    instance.remove(12);
    tools->assertFalse(instance.search(12));

    tools->description("remove root node (8)");
    tools->assertTrue(instance.search(8));
    instance.remove(8);
    tools->assertFalse(instance.search(8));

    tools->description("remove root node (3)");
    tools->assertTrue(instance.search(3));
    instance.remove(3);
    tools->assertFalse(instance.search(3));

    tools->description("remove root node (2)");
    tools->assertTrue(instance.search(2));
    instance.remove(2);
    tools->assertFalse(instance.search(2));

    tools->description("remove root node (1)");
    tools->assertTrue(instance.search(1));
    instance.remove(1);
    tools->assertFalse(instance.search(1));
    tools->assertTrue(instance.isEmpty());
  }
}

void TestBinarySearchTree::processNodes()
{
  tools->setFunctionName("processNodes");
  {
    BinarySearchTree<int> instance;
    instance.insert(5);
    instance.insert(10);
    instance.insert(3);
    instance.insert(2);
    instance.insert(12);
    instance.insert(6);
    instance.insert(8);
    instance.insert(1);

    tools->description("           5");
    tools->description("     3          10");
    tools->description("  2     -      6  12");
    tools->description(" 1 -            8");


    vfp<int> print = TestBinarySearchTree::nodePrint;
    stringstream sstream;

    tools->description("InOrder: ");
    clearSStreams(sstream);
    instance.inOrder( print );
    sstream << "1,2,3,5,6,8,10,12,";
    tools->assertEquals( printString.str() ,sstream.str());

    tools->description("PreOrder");
    clearSStreams(sstream);
    instance.preOrder( print );
    sstream << "5,3,2,1,10,6,8,12,";
    tools->assertEquals( printString.str() ,sstream.str());

    tools->description("PostOrder");
    clearSStreams(sstream);
    instance.postOrder( print );
    sstream << "1,2,3,8,6,12,10,5,";
    tools->assertEquals( printString.str() ,sstream.str());
  }
}

void TestBinarySearchTree::clearSStreams(stringstream &sstream)
{
  TestBinarySearchTree::printString.clear();
  TestBinarySearchTree::printString.str("");
  sstream.clear();
  sstream.str("");
}

void TestBinarySearchTree::search()
{
  tools->setFunctionName("search");
  {
    BinarySearchTree<int> instance;
    instance.insert(5);
    instance.insert(10);
    instance.insert(3);
    instance.insert(2);
    instance.insert(12);
    instance.insert(6);
    instance.insert(8);
    instance.insert(1);

    tools->assertTrue(instance.search(5));
    tools->assertTrue(instance.search(10));
    tools->assertTrue(instance.search(3));
    tools->assertTrue(instance.search(2));
    tools->assertTrue(instance.search(12));
    tools->assertTrue(instance.search(6));
    tools->assertTrue(instance.search(8));
    tools->assertTrue(instance.search(1));

    tools->assertFalse(instance.search(0));
    tools->assertFalse(instance.search(4));
    tools->assertFalse(instance.search(7));
    tools->assertFalse(instance.search(9));
    tools->assertFalse(instance.search(11));
    tools->assertFalse(instance.search(13));

  }
}

template <class T>
void TestBinarySearchTree::nodePrint(T &data)
{
  printString << data << ",";
}
