local clua = require 'clua.clua'
local nn = require 'nn'

-- Create a new module
-- It will be named "MyModule"
-- Will inherit from "nn.Module"
-- Will be stored in the table "clua"
local MyModule, parent = torch.class("clua.MyModule", "nn.Module", clua)

-- Define the initialization function
function MyModule:__init(scale)
    -- Call the initialization function from the parent class
    -- For nn.Module, it will initialise the self.output and
    -- self.gradInput tensor
    parent.__init(self)

    -- Save the argument as a class member
    self.scale = scale
end

-- Override the updateOutput function
function MyModule:updateOutput(input)
    -- Resize the output according to the input
    self.output:resizeAs(input)

    -- Compute the output of the module
    self.output:copy(input * self.scale)

    -- Return the output
    return self.output
end

-- Override the updateGradInput function
function MyModule:updateGradInput(input, gradOutput)
    -- Resize the gradient input
    self.gradInput:resizeAs(input)

    -- Compute the gradient of the loss with respect to the input
    self.gradInput:copy(gradOutput * self.scale)

    -- Return the gradient wrt the input
    return self.gradInput
end
