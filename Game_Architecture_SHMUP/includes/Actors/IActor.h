#pragma once

namespace Actors
{
	class IActor
	{
	public:
		virtual ~IActor() {}
		virtual void Move() = 0;
		virtual void Display() = 0;
	};
}