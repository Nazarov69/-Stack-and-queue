#include <../gtest/gtest.h>
#include <../Stacklib/Stack.h>

TEST(stack, can_create_default_stack){
	ASSERT_NO_THROW(Stack<int> p);
}

TEST(stack, can_not_create_stack_with_nagative_size){
	ASSERT_ANY_THROW(Stack<int> p(-5));
}

TEST(stack, can_create_stack_with_positive_size){
	ASSERT_NO_THROW(Stack<int> p(10));
}

TEST(stack, can_copy_stack){
	Stack <int> v(3);
	ASSERT_NO_THROW(Stack<int> p(v));
}

TEST(stack, can_push_and_pull){
	Stack<int> p(8);
	int ttmp = 2;
	p.PushStack(ttmp);
	EXPECT_EQ(2, p.GetStack());
}

TEST(stack, can_push_and_pull_all_size){
	Stack<int> p(6);
	int tmp_1 = 5, tmp_2 = 9, tmp_3 = 2;
	p.PushStack(tmp_1);
	p.PushStack(tmp_2);
	p.PushStack(tmp_3);
	EXPECT_EQ(2, p.GetStack());
	EXPECT_EQ(9, p.GetStack());
	EXPECT_EQ(5, p.GetStack());
}

TEST(stack, can_not_push_out_of_size){
	Stack<int> p(3);
	int tmp_1 = 1, tmp_2 = 2, tmp_3 = 7, tmp_4 = 2;
	p.PushStack(tmp_1);
	p.PushStack(tmp_2);
	p.PushStack(tmp_3);
	ASSERT_ANY_THROW(p.PushStack(tmp_4));
}

TEST(stack, can_not_pull_out_of_size){
	Stack<int> p(6);
	ASSERT_ANY_THROW(p.GetStack());
}

TEST(stack, can_copy_stack_with_any_elements){
	Stack<int> p(3);
	int tmp_1 = 4, tmp_2 = 1, tmp_3 = 3, tmp_4 = 1;
	p.PushStack(tmp_1);
	p.PushStack(tmp_2);
	p.PushStack(tmp_3);
	Stack<int> v(p);
	EXPECT_EQ(3, v.GetStack());
	EXPECT_EQ(1, v.GetStack());
	EXPECT_EQ(4, v.GetStack());
}