#include "TestNode.h"

TestNode::TestNode(TestingTools &initTools)
{
  tools = &initTools;
  tools->setClassName("Node");
}

TestNode::~TestNode()
{
  //dtor
}

void TestNode::all()
{
  creation();
  nesting();
}


void TestNode::creation()
{
  tools->setFunctionName("creation");
  {
    tools->description("Node<int> objects stored as variables.");
    Node<int> n1(10);
    Node<int> n2(100);
    tools->assertNotEquals(&n1,&n2);
    tools->assertTypeEquals(n1,n2);
    tools->assertEquals(n1.data, 10);
    tools->assertEquals(n2.data, 100);
    tools->assertNotEquals(n1.data, n2.data);
    n2.data = 10;
    tools->assertEquals(n1.data, n2.data);
  }
  {
    tools->description("Node<int> objects stored as pointers.");
    Node<int> *n1 = new Node<int>(10);
    Node<int> *n2 = new Node<int>(100);
    tools->assertNotEquals(n1,n2);
    tools->assertTypeEquals(n1,n2);
    tools->assertTypeEquals(*n1,*n2);
    tools->assertEquals(n1->data, 10);
    tools->assertEquals(n2->data, 100);
    tools->assertNotEquals(n1->data, n2->data);
    n2->data = 10;
    tools->assertEquals(n1->data, n2->data);
    delete n1;
    delete n2;
    n1 = n2 = nullptr;
    tools->assertTypeEquals(n1,n2);
  }
  {
    tools->description("Node<Date> objects stored as variables.");
    Node<Date> n1(Date(12,12,2014));
    Node<Date> n2(Date(12,12,2015));
    tools->assertNotEquals(&n1,&n2);
    tools->assertTypeEquals(n1,n2);
    tools->assertEquals(n1.data, Date(12,12,2014));
    tools->assertEquals(n2.data, Date(12,12,2015));
    tools->assertNotEquals(n1.data, n2.data);
    n1.data = Date(19,5,2016);
    n2.data = Date(19,5,2016);
    tools->assertEquals(n1.data, n2.data);
  }
  {
    tools->description("Node<Date> objects stored as pointers.");
    Node<Date> *n1 = new Node<Date>(Date(12,12,2014));
    Node<Date> *n2 = new Node<Date>(Date(12,12,2015));
    tools->assertNotEquals(n1,n2);
    tools->assertTypeEquals(n1,n2);
    tools->assertTypeEquals(*n1,*n2);
    tools->assertEquals(n1->data, Date(12,12,2014));
    tools->assertEquals(n2->data, Date(12,12,2015));
    tools->assertNotEquals(n1->data, n2->data);
    n1->data = Date(19,5,2016);
    n2->data = Date(19,5,2016);
    tools->assertEquals(n1->data, n2->data);
    delete n1;
    delete n2;
    n1 = n2 = nullptr;
    tools->assertTypeEquals(n1,n2);
  }
}

void TestNode::nesting()
{
  tools->setFunctionName("nesting");
  {
    /*
          n1
      n2      n3
    n4  n5  n6  n7

    */
    tools->description("Nesting Node<int> objects and pointers.");
    Node<int> n1(10);
    Node<int> n2(20);
    Node<int> n4(40);
    Node<int> n5(50);
    Node<int> *n6,*n7,*n3;
    n3 = new Node<int>(30);
    n6 = new Node<int>(60);
    n7 = new Node<int>(70);

    n1.lnode = &n2;
    n1.rnode = n3;
    n2.lnode = &n4;
    n2.rnode = &n5;
    n3->lnode = n6;
    n3->rnode = n7;

    tools->description("Traversal from root node.");

    tools->assertEquals(n1.data,10);
    tools->assertEquals(n1.lnode,&n2);
    tools->assertEquals(n1.lnode->data,20);
    tools->assertEquals(n1.rnode,n3);
    tools->assertEquals(n1.rnode->data,30);
    tools->assertEquals(n1.lnode->lnode->data,40);
    tools->assertEquals(n1.lnode->rnode->data,50);
    tools->assertEquals(n1.rnode->lnode->data,60);
    tools->assertEquals(n1.rnode->rnode->data,70);

    tools->description("Links on leaves set to nullptr.");
    tools->assertTrue(n1.lnode->lnode->lnode == nullptr);
    tools->assertTrue(n1.lnode->lnode->rnode == nullptr);
    tools->assertTrue(n1.lnode->rnode->lnode == nullptr);
    tools->assertTrue(n1.lnode->rnode->rnode == nullptr);

    tools->assertTrue(n1.rnode->lnode->lnode == nullptr);
    tools->assertTrue(n1.rnode->lnode->rnode == nullptr);
    tools->assertTrue(n1.rnode->rnode->lnode == nullptr);
    tools->assertTrue(n1.rnode->rnode->rnode == nullptr);
  }

  {
    /*
          n1
      n2      n3
    n4  n5  n6  n7

    */
    tools->description("Nesting Node<Date> objects and pointers.");
    Node<Date> n1(Date(10,5,2016));
    Node<Date> n2(Date(20,5,2016));
    Node<Date> n4(Date(20,6,2016));
    Node<Date> n5(Date(10,8,2016));
    Node<Date> *n6,*n7,*n3;
    n3 = new Node<Date>(Date(10,6,2016));
    n6 = new Node<Date>(Date(20,8,2016));
    n7 = new Node<Date>(Date(30,8,2016));

    n1.lnode = &n2;
    n1.rnode = n3;
    n2.lnode = &n4;
    n2.rnode = &n5;

    n3->lnode = n6;
    n3->rnode = n7;

    tools->description("Traversal from root node.");

    tools->assertEquals(n1.data,Date(10,5,2016));
    tools->assertEquals(n1.lnode,&n2);
    tools->assertEquals(n1.lnode->data,Date(20,5,2016));//n2
    tools->assertEquals(n1.rnode,n3);
    tools->assertEquals(n1.rnode->data,Date(10,6,2016));
    tools->assertEquals(n1.lnode->lnode->data,Date(20,6,2016));
    tools->assertEquals(n1.lnode->rnode->data,Date(10,8,2016));
    tools->assertEquals(n1.rnode->lnode->data,Date(20,8,2016));
    tools->assertEquals(n1.rnode->rnode->data,Date(30,8,2016));

    tools->description("Links on leaves set to nullptr.");
    tools->assertTrue(n1.lnode->lnode->lnode == nullptr);
    tools->assertTrue(n1.lnode->lnode->rnode == nullptr);
    tools->assertTrue(n1.lnode->rnode->lnode == nullptr);
    tools->assertTrue(n1.lnode->rnode->rnode == nullptr);

    tools->assertTrue(n1.rnode->lnode->lnode == nullptr);
    tools->assertTrue(n1.rnode->lnode->rnode == nullptr);
    tools->assertTrue(n1.rnode->rnode->lnode == nullptr);
    tools->assertTrue(n1.rnode->rnode->rnode == nullptr);

    delete n3, n6, n7;
  }
}
