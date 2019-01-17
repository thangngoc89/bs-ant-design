[@bs.module] external tag: ReasonReact.reactClass = "antd/lib/tag";

[%bs.raw {|require("antd/lib/tag/style")|}];

[@bs.obj]
external makeProps:
  (
    ~prefixCls: string=?,
    ~className: string=?,
    ~color: string=?,
    ~closable: bool=?,
    ~visible: bool=?,
    ~onClose: unit => unit=?,
    ~afterClose: unit => unit=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~prefixCls=?,
      ~className=?,
      ~color=?,
      ~closable=?,
      ~visible=?,
      ~onClose=?,
      ~afterClose=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=tag,
    ~props=
      makeProps(
        ~prefixCls?,
        ~className?,
        ~color?,
        ~closable?,
        ~visible?,
        ~onClose?,
        ~afterClose?,
        ~style?,
        (),
      ),
    children,
  );