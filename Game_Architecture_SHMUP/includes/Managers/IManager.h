#pragma once

namespace Managers
{
	class IManager
	{
	public:
		virtual ~IManager() {}
		virtual void Setup() = 0;
		virtual void Update() = 0;
	};
}