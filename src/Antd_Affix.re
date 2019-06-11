[@bs.module "antd/lib/affix"]
external affix: ReasonReact.reactClass = "default";

[%bs.raw {|require("antd/lib/affix/style")|}];

[@bs.obj]
external makeProps:
  (
    ~offsetTop: int=?,
    ~offset: int=?,
    ~offsetBottom: int=?,
    ~style: ReactDOMRe.Style.t=?,
    ~onChange: bool => unit=?,
    ~prefixCls: string=?,
    unit
  ) =>
  _ =
  "";
/** 设置 Affix 需要监听其滚动事件的元素，值为一个返回对应 DOM 元素的函数 */
/* target?: () => Window | HTMLElement | null; */

let make =
    (
      ~offsetTop=?,
      ~offset=?,
      ~offsetBottom=?,
      ~style=?,
      ~onChange=?,
      ~prefixCls=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=affix,
    ~props=
      makeProps(
        ~offsetTop?,
        ~offset?,
        ~offsetBottom?,
        ~style?,
        ~onChange?,
        ~prefixCls?,
        (),
      ),
    children,
  );