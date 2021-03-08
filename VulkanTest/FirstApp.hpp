#pragma once

#include "LveWindow.hpp"
#include "LvePipeline.hpp"
#include "LveDevice.hpp"
#include "LveSwapChain.h"

#include <memory>
#include <vector>

namespace lve {

	class FirstApp
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		FirstApp();
		~FirstApp();

		FirstApp(const FirstApp&) = delete;
		FirstApp& operator=(const FirstApp&) = delete;

		void run();

	private:
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();

		LveWindow lveWindow{ WIDTH, HEIGHT, "Hello Vulkan!" };
		LveDevice lveDevice{ lveWindow };

		LveSwapChain lveSwapChain{ lveDevice, lveWindow.getExtent() };
		VkPipelineLayout pipelineLayout;

		std::unique_ptr<LvePipeline> lvePipeline;
		std::vector<VkCommandBuffer> commandBuffers;

	};


}

