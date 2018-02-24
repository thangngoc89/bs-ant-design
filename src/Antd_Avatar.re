open Antd_Helpers;

module IconName = Antd_IconName;

[@bs.module] external reactClass : ReasonReact.reactClass = "antd/lib/avatar";

[%bs.raw {|require("antd/lib/avatar/style")|}];

[@bs.deriving jsConverter]
type avatarShape = [ | `circle | `square];

[@bs.deriving jsConverter]
type avatarSize = [ | `small | `default | `large];

[@bs.obj]
external makeProps :
(
    ~shape: string=?,
    ~size: string=?,
    ~src: string=?,
    ~icon: IconName.t=?,
    ~style: ReactDOMRe.Style.t=?,
    ~prefixCls: string=?,
    ~className: string=?,
    unit
) =>_ = "";

let make =
    (
        ~shape=?,
        ~size=?,
        ~src=?,
        ~icon=?,
        ~style=?,
        ~prefixCls=?,
        ~className=?,
        children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~shape=?Js.Option.map([@bs] (b => avatarShapeToJs(b)), shape),
        ~size=?Js.Option.map([@bs] (b => avatarSizeToJs(b)), size),
        ~src?,
        ~icon?,
        ~style?,
        ~prefixCls?,
        ~className?,
        ()
      ),
    children
  );