local clua = require 'clua.clua'
local nn = require 'nn'

local MyModule, parent = torch.class("clua.MyModule", "nn.Module", clua)

function MyModule:__init(scale)
    parent.__init(self)

    self.scale = scale
end

function MyModule:updateOutput(input)
    -- Compute the output of the module using our c function
    clua.c.cScale(self.output, input, self.scale)

    return self.output
end

function MyModule:updateGradInput(input, gradOutput)
    self.gradInput:resizeAs(input)

    self.gradInput:copy(gradOutput * self.scale)

    return self.gradInput
end
