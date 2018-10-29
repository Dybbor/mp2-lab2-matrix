#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one) //—копированный вектор равен исходному
{
	const int size = 3;
	TVector <int> Vector1(size);
	for (int i = 0; i <size; i++)
		Vector1[i] = i;
	TVector <int >Vector2(Vector1);
	EXPECT_EQ(1,(Vector1==(Vector2)));
	//ADD_FAILURE();
}

TEST(TVector, copied_vector_has_its_own_memory) //—копированный вектор имеет собственную пам€ть
{
	ADD_FAILURE();
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector <int> vector(5);
	ASSERT_ANY_THROW(vector [-2]);
 // ADD_FAILURE();
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector <int> vector(5);
	ASSERT_ANY_THROW(vector[10]);
  //ADD_FAILURE();
}

TEST(TVector, can_assign_vector_to_itself)
{
  ADD_FAILURE();
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
  ADD_FAILURE();
}

TEST(TVector, assign_operator_change_vector_size)
{
  ADD_FAILURE();
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  ADD_FAILURE();
}

TEST(TVector, compare_equal_vectors_return_true)
{
	const int size = 5;
	TVector <int> Vector1(size), Vector2(size);
	for (int i = 0; i < size; i++)
	{
		Vector1[i] = i;
		Vector2[i] = i;
	}
	EXPECT_EQ(1, Vector1 == Vector2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	const int size = 5;
	TVector <int> Vector1(size);
	for (int i = 0; i < size; i++)
		Vector1[i] = i;
	EXPECT_EQ(1, Vector1 == Vector1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector <int> Vector1(3), Vector2(5);
	EXPECT_EQ(1, Vector1 != Vector2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector <int> Vector1(3), Vector2(3);
	for (int i = 0; i < 3; i++)
	{
		Vector1[i] = 3;
		Vector2[i] = 1;
	}
	EXPECT_EQ(Vector1,Vector2 + 2);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector <int> Vector1(3), Vector2(3);
	for (int i = 0; i < 3; i++)
	{
		Vector1[i] = 3;
		Vector2[i] = 1;
	}
	EXPECT_EQ(Vector2, Vector1 - 2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector <int> Vector1(3), Vector2(3);
	for (int i = 0; i < 3; i++)
	{
		Vector1[i] = 3;
		Vector2[i] = 1;
	}
	EXPECT_EQ(Vector1, Vector2 *3);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector <int> Vector1(3), Vector2(3),Vector3(3);
	for (int i = 0; i < 3; i++)
	{
		Vector1[i] = 3;
		Vector2[i] = 1;
		Vector3[i] = 4;
	}
	EXPECT_EQ(Vector3, Vector1 + Vector2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector <int> Vector1(3), Vector2(5);
	EXPECT_ANY_THROW(Vector1 + Vector2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector <int> Vector1(3), Vector2(3), Vector3(3);
	for (int i = 0; i < 3; i++)
	{
		Vector1[i] = 3;
		Vector2[i] = 1;
		Vector3[i] = 4;
	}
	EXPECT_EQ(Vector2, Vector3 - Vector1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector <int> Vector1(3), Vector2(5);
	EXPECT_ANY_THROW(Vector1 - Vector2);

}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector <int> Vector1(5), Vector2(5);
	for (int i = 0; i < 5; i++)
	{
		Vector1[i] = 1;
		Vector2[i] = 5;
	}
	EXPECT_EQ(25,Vector1*Vector2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector <int> Vector1(3), Vector2(5);
	EXPECT_ANY_THROW(Vector1*Vector2);
}

