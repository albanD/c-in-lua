-- Import our module
local ok, clua = pcall(require, "clua")
if not ok then
    print("### clua module not found")
    error("### Please install one of the sample modules")
end
assert(clua.MyModule, "clua does not contain MyModule")

-- Create a sample network
local scale = 2
local network = nn.Sequential()
network:add(clua.MyModule(scale))

-- Test the module for different types of tensors
local testModule = function(tensorType)
    print("### Testing "..tensorType)
    network:type(tensorType)
    local input = torch.rand(10,10):type(tensorType)
    local expected = input:clone() * 2

    local ok, output = pcall(network.forward, network, input)
    if not ok then
        print("### Error forwarding a "..tensorType..".")
        print("### Message: "..output)
        return
    end

    if not output:eq(expected) then
        print("### The output of the module is not correct")
        print("### Result:")
        print(output)
        print("### Expected:")
        print(expected)
        return
    end
    print("### Passed.")
end

testModule("torch.FloatTensor")
testModule("torch.DoubleTensor")
