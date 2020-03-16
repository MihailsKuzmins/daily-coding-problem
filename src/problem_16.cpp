// You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, with the following API:
//  - record(order_id): adds the order_id to the log
//  - get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
// You should be as efficient with time and space as possible.

// Example:
// Queue queue(5);
// queue.record(1);
// queue.record(2);
// queue.record(3);
// queue.record(4);
// queue.record(5);
// queue.record(6);
// queue.record(7);
//
// auto last_2 = queue.get_last(2);
// auto last_3 = queue.get_last(3);

class Queue
{
private:
	int* m_items;
	unsigned int m_capacity, m_size;
	unsigned int m_start_index, m_end_index;
	int increment_index(const unsigned int& index) const noexcept
	{
		const auto sum = index + 1;
		return sum >= m_capacity ? 0 : sum;
	}
public:
	Queue(const unsigned int capacity) : m_items(new int[capacity]), m_start_index(0), m_end_index(0), m_capacity(capacity), m_size(0) {};
	~Queue() noexcept { delete[] m_items; }
	void record(const int order_id) noexcept
	{
		if (m_size)
		{
			m_end_index = increment_index(m_end_index);

			if (m_end_index == m_start_index)
				m_start_index = increment_index(m_start_index);
		}

		m_items[m_end_index] = order_id;

		if (m_size < m_capacity - 1)
			m_size++;
	}
	const int get_last(const int last_id)
	{
		int subtract = m_end_index - last_id + 1;
		if (subtract < 0)
			subtract = m_capacity + subtract;

		return m_items[subtract];
	}
};
