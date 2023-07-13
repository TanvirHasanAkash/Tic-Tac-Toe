#pragma once

struct State
{
	char label;

	explicit State(const char label)
		: label(label)
	{ }

	friend bool operator==(const State& lhs, const State& rhs)
	{
		return lhs.label == rhs.label;
	}

	friend bool operator!=(const State& lhs, const State& rhs)
	{
		return lhs.label != rhs.label;
	}
};

static State none('-');
static State playerX('X');
static State playerO('O');

#if _DEBUG
static State test('T');
#endif
