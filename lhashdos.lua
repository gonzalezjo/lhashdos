-- gonzalez, j | december 2017
-- lhashdos.lua

local ffi = require 'ffi'
local bit = require 'bit'
local char_array

do
	math.randomseed(os.time())
	char_array = ffi.new 'char[15]'
	local lowest_char = math.random((' o'):byte(1, 2))
	for i = lowest_char, lowest_char + 15 do
		char_array[i - lowest_char] = i
	end

	ffi.cdef 'typedef char collidable[32];'
end

local function get(spacer, outputs_desired, restart_position)
	local bit_rshift = bit.rshift
	local start = restart_position or 1
	local buf = ffi.new('collidable[?]', outputs_desired)
	ffi.fill(buf, ffi.sizeof(buf), spacer:byte())

	for buf_pos = 0, outputs_desired - start do
		for offset = 0, 30, 2 do
			buf[buf_pos][offset] = char_array[bit_rshift(buf_pos + start, offset) % 15]
		end
	end

	return buf
end
