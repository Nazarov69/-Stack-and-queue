#include <../gtest/gtest.h>
#include <../Queuelib/Queue.h>

TEST(queue, can_create_default_queue){
	ASSERT_NO_THROW(Queue<int> p);
}

TEST(queue, can_not_create_queue_with_nagative_size){
	ASSERT_ANY_THROW(Queue<int> p(-5));
}
TEST(queue, can_create_queue_with_positive_size){
	ASSERT_NO_THROW(Queue<int> p(25));
}

TEST(queue, can_copy_queue){
	Queue <int> v(17);
	ASSERT_NO_THROW(Queue<int> p(v));
}

TEST(queue, can_push_and_pull){
	Queue <int> p(1);
	int ttmp = 1;
	p.PushQueue(ttmp);
	EXPECT_EQ(1, p.GetQueue());
}

TEST(queue, can_push_and_pull_size_3){
	Queue<int> p(3);
	int tmp_1 = 3, tmp_2 = 8, tmp_3 = 1;
	p.PushQueue(tmp_1);
	p.PushQueue(tmp_2);
	p.PushQueue(tmp_3);
	EXPECT_EQ(3, p.GetQueue());
	EXPECT_EQ(8, p.GetQueue());
	EXPECT_EQ(1, p.GetQueue());
}

TEST(queue, can_not_push_out_of_size)
{
	Queue<int> p(3);
	int tmp_1 = 6, tmp_2 = 2, tmp_3 = 7, tmp_4 = -9;
	p.PushQueue(tmp_1);
	p.PushQueue(tmp_2);
	p.PushQueue(tmp_3);

	ASSERT_ANY_THROW(p.PushQueue(tmp_4));
}

TEST(queue, can_not_pull_out_of_size){
	Queue<int> p(4);
	ASSERT_ANY_THROW(p.GetQueue());
}

TEST(queue, can_copy_queue_with_any_elements){
	Queue<int> p(3);
	int tmp_1 = 4, tmp_2 = 6, tmp_3 = 9, tmp_4 = 6;
	p.PushQueue(tmp_1);
	p.PushQueue(tmp_2);
	p.PushQueue(tmp_3);

	Queue<int> t(p);
	EXPECT_EQ(1, t.GetQueue());
	EXPECT_EQ(2, t.GetQueue());
	EXPECT_EQ(7, t.GetQueue());
	
	
}