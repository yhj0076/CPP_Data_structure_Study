#pragma once

#include <cassert>		// 디버깅용 헤더

template <typename T>
class TSingleListNode
{
private : 
	T m_Data;						// 데이터
	TSingleListNode* m_pNextNode;	// 다음 노드의 주소값

private :
	template <typename T>
	friend class TSingleList;		// friend를 통해서 TSingleList는 TSingleListNode의 private 데이터까지 접근이 가능해진다.

public : 
	TSingleListNode() :
		m_pNextNode(nullptr) {}
	~TSingleListNode() {}
};

template <typename T>
class TSingleList
{
private : 
	typedef TSingleListNode<T> NODE;
	typedef TSingleListNode<T>* PNODE;

private : 
	PNODE m_pHead;				// 제일 앞에 있는 머리 노드
	int m_nCurCount;			// 현재 몇 개의 데이터가 리스트에 존재하는가

public : 
	// Create
	TSingleList() : 
		m_pHead(nullptr), m_nCurCount(0)
	{
		m_pHead = new NODE;
		m_pHead->m_pNextNode = nullptr;
	}

	// Destroy
	~TSingleList()
	{
		// 리스트에 있는 노드를 다 삭제시킨다.
		while (m_nCurCount != 0) 
		{
			// 지울 노드는 끝부터 차례로 지운다.
			PNODE delNode = m_pHead->m_pNextNode;

			// 끝까지 간다.
			while (delNode->m_pNextNode != nullptr)
			{
				PNODE delNextNode = delNode->m_pNextNode;
				delNode = delNextNode;
			}

			// 끝 노드를 삭제 시킨다.
			delete delNode;
			// 현재 리스트의 크기를 감소시킨다.
			--m_nCurCount;
		}

		delete m_pHead;
	}

public : 
	// Insert
	void Insert(const T& _data)
	{
		PNODE newNode = new NODE;
		newNode->m_Data = _data;

		// 만약 비어 있다면
		if (m_pHead->m_pNextNode == nullptr)
		{
			m_pHead->m_pNextNode = newNode;
		}
		// 만약 데이터가 있다면
		else
		{
			// 마지막 노드를 찾을 노드를 구한다.
			PNODE lastNode = m_pHead->m_pNextNode;

			// 마지막 노드를 찾을 때까지 
			while (lastNode->m_pNextNode != nullptr)
			{
				PNODE nextNode = lastNode->m_pNextNode;
				lastNode = nextNode;
			}

			lastNode->m_pNextNode = newNode;
		}
		m_nCurCount++;		// 노드값이 추가된다.
	}

	void Delete(int _position)
	{
		// 만약 이 문장이 틀리다면 바로 에러 처리를 한다.
		assert(_position <= m_nCurCount);

		PNODE delNode = m_pHead;

		while (_position != 0)
		{
			PNODE delNextNode = delNode->m_pNextNode;
			delNode = delNextNode;
			--_position;
		}

		delete delNode;
	}

	T Retrieve(int _position)
	{
		// 만약 이 문장이 틀리다면 바로 에러 처리를 한다.
		assert(_position <= m_nCurCount);

		PNODE findNode = m_pHead;

		while (_position != 0)
		{
			PNODE findNextNode = findNode->m_pNextNode;
			findNode = findNextNode;
			--_position;
		}

		T returnData = findNode->m_Data;
		return returnData;
	}

	bool IsEmpry() const
	{
		return m_nCurCount == 0;
	}

	int GetLength() const
	{
		return m_nCurCount;
	}
};
