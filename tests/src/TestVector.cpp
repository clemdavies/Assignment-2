#include "TestVector.h"

TestVector::TestVector(TestingTools &toolsRef)
{
  tools = &toolsRef;
  tools->setClassName("Vector");
}

TestVector::~TestVector()
{
  //dtor
}


void TestVector::all()
{
  emptyConstructor();
  paramConstructor();
  copyConstructor();
  assignmentOperator();
  get();
  getSize();
  getMaxSize();
  insert();
  clear();
  empty();
  increaseSize();
}

void TestVector::emptyConstructor()
{
	tools->setFunctionName("emptyConstructor");
	{
		Vector<int> instance1;
		Vector<float> instance2;
		Vector<int> instance3;
    tools->assertTypeNotEquals(instance1,instance2);
    tools->assertTypeEquals(instance1,instance3);
	}
	{
		Vector<int*> instance1;
		Vector<float*> instance2;
		Vector<int*> instance3;
    tools->assertTypeNotEquals(instance1,instance2);
    tools->assertTypeEquals(instance1,instance3);
	}
}

void TestVector::paramConstructor()
{
	tools->setFunctionName("paramConstructor");
	{
		Vector<int> instance(3);
		tools->assertEquals(instance.getMaxSize(),(unsigned)10);
	}
	{
		Vector<int> instance(100);
		tools->assertEquals(instance.getMaxSize(),(unsigned)100);
	}
	{
		Vector<const char *> instance(100);
		tools->assertEquals(instance.getMaxSize(),(unsigned)100);
	}
	{
	  tools->description("Vector of Vectors");
		Vector<Vector<int>> instance;
		Vector<int> inner;
		inner.insert(0,55);
		instance.insert(0,inner);
		tools->assertEquals(instance.getSize(),(unsigned)1);
		tools->assertEquals(instance.get(0).getSize(),(unsigned)1);
		tools->assertEquals(instance.getMaxSize(),(unsigned)10);
		tools->assertEquals(instance.get(0).getMaxSize(),(unsigned)10);
		tools->assertEquals(instance.get(0).get(0),55);
	}
}

void TestVector::copyConstructor()
{
	tools->setFunctionName("copyConstructor");
	{
		Vector<int> copyFrom;
		copyFrom.insert(0,5);
		copyFrom.insert(1,6);
		copyFrom.insert(2,7);
		tools->assertEquals( copyFrom.get(0), 5);
		tools->assertEquals( copyFrom.get(1), 6);
		tools->assertEquals( copyFrom.get(2), 7);
		Vector<int> copyTo( copyFrom );
		tools->assertEquals(copyTo.get(0),5);
		tools->assertEquals(copyTo.get(1),6);
		tools->assertEquals(copyTo.get(2),7);
		tools->assertEquals(copyFrom.getSize(),copyTo.getSize());
		tools->assertEquals(copyFrom.getMaxSize(),copyTo.getMaxSize());
	}
	{
		Vector<const char *> copyFrom;
		copyFrom.insert(0,"Clem");
		copyFrom.insert(1,"W");
		copyFrom.insert(2,"Davies");
		tools->assertEquals( copyFrom.get(0), "Clem");
		tools->assertEquals( copyFrom.get(1), "W");
		tools->assertEquals( copyFrom.get(2), "Davies");
		Vector<const char *> copyTo( copyFrom );
		tools->assertEquals(copyTo.get(2),"Davies");
		tools->assertEquals(copyTo.get(1),"W");
		tools->assertEquals(copyTo.get(0),"Clem");
	}
}

void TestVector::assignmentOperator()
{
	tools->setFunctionName("assignementOperator");
	{
	  Vector<int> copyFrom;
		Vector<int> instance = copyFrom;
    tools->assertTypeEquals(instance,copyFrom);
    tools->assertEquals(instance.getMaxSize(),(unsigned)10);
    tools->assertEquals(instance.getSize(),(unsigned)0);
	}
	{
	  Vector<int> copyFrom(5);
	  copyFrom.insert(0,2);
	  copyFrom.insert(1,4);
	  copyFrom.insert(2,8);
	  copyFrom.insert(3,16);
	  copyFrom.insert(4,32);
		Vector<int> instance = copyFrom;
    tools->assertEquals(instance.getMaxSize(),(unsigned)10);
    tools->assertEquals(copyFrom.getSize(),(unsigned)5);
    tools->assertEquals(instance.getSize(),(unsigned)5);
    tools->assertEquals(instance.get(4),32);
    tools->assertEquals(instance.get(3),16);
    tools->assertEquals(instance.get(2),8);
    tools->assertEquals(instance.get(1),4);
    tools->assertEquals(instance.get(0),2);
	}
}


void TestVector::get()
{
	tools->setFunctionName("get");
	{
		Vector<int> instance;
		instance.insert(0,1);
		instance.insert(1,2);
		instance.insert(2,3);
    tools->assertEquals(instance.get(0),1);
    tools->assertEquals(instance.get(1),2);
    tools->assertEquals(instance.get(2),3);
    tools->assertEquals(instance.get(2),3);
	}
}


void TestVector::getSize()
{
	tools->setFunctionName("getSize");
	{
		Vector<int> instance;
		instance.insert(0,1);
		instance.insert(1,2);
		instance.insert(2,3);
    tools->assertEquals(instance.getSize(),(unsigned)3);
    instance.insert(3,4);
    instance.insert(4,5);
    tools->assertEquals(instance.getSize(),(unsigned)5);
	}
}

void TestVector::getMaxSize()
{
	tools->setFunctionName("getMaxSize");
	{
		Vector<int> instance;
    tools->assertEquals(instance.getMaxSize(),(unsigned)10);
		instance.insert(0,1);
		instance.insert(1,2);
		instance.insert(2,3);
    tools->assertEquals(instance.getMaxSize(),(unsigned)10);
	}
	{
		Vector<int> instance(110);
    tools->assertEquals(instance.getMaxSize(),(unsigned)110);
		instance.insert(0,1);
		instance.insert(1,2);
		instance.insert(2,3);
    tools->assertEquals(instance.getMaxSize(),(unsigned)110);
	}
}

void TestVector::insert()
{
	tools->setFunctionName("insert");
	{
		Vector<int> instance;
		instance.insert(0,5);
		tools->assertEquals(instance.get(0),5);
		instance.insert(2,3);
		tools->assertEquals(instance.get(2),3);
	}
	{
		Vector<const char *> instance;
		instance.insert(0,"Clem");
		tools->assertEquals(instance.get(0),"Clem");
		instance.insert(2,"Davies");
		tools->assertEquals(instance.get(2),"Davies");
		tools->assertEquals(instance.getSize(),(unsigned)2);
	}
}

void TestVector::clear()
{
	tools->setFunctionName("clear");
	{
		Vector<int> instance;
		instance.insert(0,5);
		instance.insert(1,6);
		instance.insert(2,8);
		instance.clear();
		tools->assertTrue(instance.empty());
	}
	{
		Vector<const char *> instance;
		instance.insert(0,"Clem");
		instance.insert(1,"W");
		instance.insert(2,"Davies");
		instance.clear();
		tools->assertTrue(instance.empty());
	}
}


void TestVector::empty()
{
	tools->setFunctionName("empty");
	{
		Vector<const char *> instance;
		tools->assertTrue(instance.empty());
		instance.insert(0,"Clem");
		instance.insert(1,"W");
		instance.insert(2,"Davies");
		tools->assertFalse(instance.empty());
	}
}

void TestVector::increaseSize()
{
	tools->setFunctionName("increaseSize");
	{
		Vector<int> instance;
    tools->assertEquals( instance.getMaxSize(),(unsigned)10 );
		instance.insert(1,2);
    instance.insert(9,25);
    tools->description("insert(1,2)");
    tools->description("insert(9,25)");
		tools->assertEquals( instance.getSize(),(unsigned)2 );
		tools->assertEquals( instance.get(1),2 );
		tools->assertEquals( instance.get(9),25 );
		tools->assertEquals( instance.getSize(),(unsigned)2 );
		tools->assertEquals( instance.getMaxSize(),(unsigned)10 );
    instance.insert(15,35);
    tools->description("insert(15,35)");
		tools->assertEquals( instance.getSize(),(unsigned)3 );
		tools->assertEquals( instance.get(9),25 );
		tools->assertEquals( instance.getSize(),(unsigned)3 );
		tools->assertEquals( instance.get(15),35 );
		tools->assertEquals( instance.getSize(),(unsigned)3 );
		tools->assertEquals( instance.getMaxSize(),(unsigned)23 );
		/*
      new = ceil(old * 1.5)
      23 * 1.5 = 23 + 11.5 = 34.5 = 35
      35 * 1.5 = 35 + 17.5 = 52.5 = 53
      53 * 1.5 = 53 + 26.5 = 79.5 = 80
      80 * 1.5 = 80 + 40   = 120  = 120
		*/
		instance.insert(100,55);
    tools->description("insert(100,55)");
		tools->assertEquals( instance.getSize(),(unsigned)4 );
		tools->assertEquals( instance.getMaxSize(),(unsigned)120 );
		tools->assertEquals( instance.get(100) ,55 );

		tools->assertEquals( instance.getMaxSize(),(unsigned)120 );
		instance.clear();
    tools->description("clear()");
		tools->assertTrue( instance.empty() );
		tools->assertEquals( instance.getSize(),(unsigned)0 );
		tools->assertEquals( instance.getMaxSize(),(unsigned)120 );
	}
	{
    tools->description("loop insert");
    Vector<int> instance;
    int value;
    for(unsigned i = 0; i < 300; i++)
    {
      value = i*3;
      instance.insert(i,value);
      if(i == 10)
        tools->assertEquals(instance.get(10),30);
      if(i==100)
        tools->assertEquals(instance.get(100),300);

    }

    tools->assertEquals(instance.getSize(),(unsigned)300);
    tools->assertEquals(instance.getMaxSize(),(unsigned)540);
    tools->assertEquals(instance.get(1),3);
    tools->assertEquals(instance.get(10),30);
    tools->assertEquals(instance.get(100),300);

	}

}

