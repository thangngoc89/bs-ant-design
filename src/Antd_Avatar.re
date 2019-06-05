module IconName = Antd_IconName;

[@bs.module "antd/lib/avatar"]
external reactClass: ReasonReact.reactClass = "default";

[%bs.raw {|require("antd/lib/avatar/style")|}];

[@bs.deriving jsConverter]
type avatarShape = [ | `circle | `square];

[@bs.deriving jsConverter]
type avatarSize = [ | `small | `default | `large];

[@bs.obj]
external makeProps:
  (
    ~shape: string=?,
    ~size: string=?,
    ~src: string=?,
    ~icon: IconName.t=?,
    ~prefixCls: string=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~shape=?,
      ~size=?,
      ~src=?,
      ~icon=?,
      ~prefixCls=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~shape=?Js.Option.map((. b) => avatarShapeToJs(b), shape),
        ~size=?Js.Option.map((. b) => avatarSizeToJs(b), size),
        ~src?,
        ~icon?,
        ~prefixCls?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );