#pragma XOD require "https://github.com/amperka/SegM8"

{{#global}}
#include "segm8.h"
{{/global}}

struct State {
    uint8_t mem[sizeof(SegM8)];
    SegM8* chain;
};

using Type = State*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    State* state = getState(ctx);
    if(isSettingUp()) {
        auto cnt = getValue<input_CNT>(ctx);
        auto cs = getValue<input_CS>(ctx);
        auto d0 = getValue<input_DO>(ctx);
        auto clk = getValue<input_CLK>(ctx);
        if(d0 == 255 || clk == 255) {
            state->chain = new (state->mem) SegM8(cs, cnt);
        } else {
            state->chain = new (state->mem) SegM8(cs, d0, clk, cnt);
        }
        state->chain->begin();
        emitValue<output_DEV>(ctx, state);
    }
}
