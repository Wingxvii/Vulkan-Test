#pragma once

#include "LveWindow.hpp"
#include "LvePipeline.hpp"
#include "LveDevice.hpp"

namespace lve {

	class FirstApp
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();

	private:
		LveWindow lveWindow{ WIDTH, HEIGHT, "Hello Vulkan!" };
		LveDevice lveDevice{ lveWindow };

		LvePipeline lvePipeline{ lveDevice, "SimpleShader.vert.spv","SimpleShader.frag.spv", LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};

	};


}

